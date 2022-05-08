#include "Testbench.h"
#include "NorGate.h"

int sc_main(int argc, char* argv[])
{   
    sc_time PERIODO(10,SC_NS);
    sc_time RETARDO(10, SC_NS);
    sc_clock reloj("reloj", PERIODO, 0.5, RETARDO, true); // Se crea el reloj

    NorGate compuertaNor("compuertaNor");
    Testbench mesaDePrueba("mesaDePrueba");

    sc_signal<bool> aCable, bCable, cCable; // estos cables hacen la conexcion entre los puertos
    
    //conectamos los cables a las compuertas
    compuertaNor.aIn(aCable);  
    compuertaNor.bIn(bCable);
    compuertaNor.cOut(cCable);

    mesaDePrueba.aOut(aCable);
    mesaDePrueba.bOut(bCable);
    mesaDePrueba.cIn(cCable);

    //Conectamos el reloj a la mesa de pruebas
    mesaDePrueba.clkIn(reloj); 

    sc_start(); //Iniciamos la simulacion
    
    return 0;
}