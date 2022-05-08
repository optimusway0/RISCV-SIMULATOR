#include "NotGate.h"
#include "Testbench.h"

int sc_main(int argc, char* argv[])
{   
    sc_time PERIOD(10, SC_NS); //SC_PS SC_SEC . . .
    sc_time DELAY(10, SC_NS);
    sc_clock clock("clock", PERIOD, 0.5, DELAY, true); // creamos el reloj

    NotGate compuertaNot("compuertaNot");
    Testbench mesaDePrueba("mesaDePrueba");

    //Creamos los cables
    sc_signal<bool> aCable, bCable; 
    
    //Conectamos los cables a las entradas y salidas de la compuerta NOT con Testbench.h
    compuertaNot.aIn(aCable);
    compuertaNot.bOut(bCable);

    mesaDePrueba.aOut(aCable);
    mesaDePrueba.bIn(bCable);

    mesaDePrueba.clkIn(clock); //Conectamos el reloj

    sc_start();

    return 0;
}