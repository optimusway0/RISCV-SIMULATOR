#ifndef FULL_ADDER_H
#define FULL_ADDER_H

#include <systemc.h>
#include "Gates/AndGate/AndGate.h"
#include "Gates/OrGate/OrGate.h"
#include "Gates/XorGate/XorGate.h"  

class FullAdder : public sc_module
{
private:
    AndGate *and1, *and2;
    OrGate *orGate;
    XorGate *xor1, *xor2;

public:
    SC_CTOR(FullAdder);
    ~FullAdder();

    //Entradas y salidas
    sc_in<bool> aIn, bIn, carryIn;
    sc_out<bool> resultOut, carryOut;

    //cableado interno
    sc_signal<bool> sg0, sg1, sg2;
};

#endif //FULL_ADDER_H