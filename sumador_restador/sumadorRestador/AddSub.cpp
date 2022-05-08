#include "AddSub.h"

AddSub::AddSub(sc_module_name mn) : sc_module(mn), 
    fullAdders("fullAdders", NUM_FULL_ADDERS), 
    andGates("andGates", NUM_ANDS),
    orGate("orGate"),
    notGateS("notGateS", NUM_NOTS),
    xorGateS("xorGateS", NUM_XORS)
{
    //Hacemos las conexiones internas del sumador/restador
    
    //Conecto la señal de control controlIn al primer fullAdder
    fullAdders[0].carryIn(controlIn);

    for(int i = 0; i<NUM_XORS; i++) 
    {
        //Conecto las señales de control a sus respectivas compuertas XOR
        xorGateS[i].aIn(controlIn);

        //Conecto los bits de la entrada sc_in< sc_int<ADD_SUB_BITS> > bIn;
        xorGateS[i].bIn( bSg[i]);

        //Conecto las salida de los XOR Gates a las entradas bIn de los fullAdder
        xorGateS[i].cOut(xorSg[i]);
        fullAdders[i].bIn(xorSg[i]);

        //Conecto los bits de la entrada sc_in< sc_int<ADD_SUB_BITS> > aIn; del AddSub
        fullAdders[i].aIn(aSg[i]);

        //Conecto las salidas de los fullAdders a la salida sc_out< sc_int<ADD_SUB_BITS> > rOut del AddSub;
        fullAdders[i].resultOut(rSg[i]);
    }   
    
    //Conecto las salidas de acarreo entre los FullAdders
    for (size_t i = 0; i < NUM_FULL_ADDERS-1; i++)
    {
        fullAdders[i].carryOut(carrySg[i]);
        fullAdders[i+1].carryIn(carrySg[i]);    
    }
    
    //Conecto la salida de acarreo del ultimo fullAdder con la salida sc_out<bool> carryOut; del AddSub
    fullAdders[NUM_FULL_ADDERS - 1].carryOut(carryOut);

    //Conecto el circuito para obtener el overflow
    notGateS[0].aIn(aSg[ADD_SUB_BITS - 1]);
    notGateS[0].bOut(notSg[0]);
    
    notGateS[1].aIn(xorSg[NUM_XORS - 1]);
    notGateS[1].bOut(notSg[1]); 

    notGateS[2].aIn(rSg[NUM_FULL_ADDERS - 1]);
    notGateS[2].bOut(notSg[2]);

    andGates[0].aIn(rSg[NUM_FULL_ADDERS - 1]);
    andGates[0].bIn(notSg[1]);
    andGates[0].cIn(notSg[0]);
    andGates[0].dOut(andSg[0]);

    andGates[1].aIn(notSg[2]);
    andGates[1].bIn(xorSg[NUM_XORS - 1]);
    andGates[1].cIn(aSg[ADD_SUB_BITS - 1 ]);
    andGates[1].dOut(andSg[1]);

    orGate.aIn(andSg[0]);
    orGate.bIn(andSg[1]);
    orGate.cOut(overflowOut);

    SC_METHOD(assemble);
    sensitive << aIn << bIn << controlIn;
    for (size_t i = 0; i<NUM_FULL_ADDERS; i++){ 
        sensitive << rSg[i];
    }
}

AddSub::~AddSub() { }

void AddSub::assemble()
{
    sc_int<ADD_SUB_BITS> temp;
    for(int i = 0; i<ADD_SUB_BITS; i++)
    {
        aSg[i] = aIn.read()[i];
        bSg[i] = bIn.read()[i];
        temp[i] = rSg[i];
    }

    rOut.write(temp);
}