#ifndef NOT_GATE_H
#define NOT_GATE_H

#include <systemc.h>

class NotGate : public sc_module
{
private:
    void complementar();
public:
    SC_CTOR(NotGate);
    ~NotGate();

    //Puertos de entrada y salida de la compuerta NOT
    sc_in<bool> aIn;
    sc_out<bool> bOut;

};

#endif