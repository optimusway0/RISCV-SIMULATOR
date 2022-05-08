#ifndef OR_GATE_H
#define OR_GATE_H

#include <systemc.h>

class OrGate : public sc_module {
private:
    void operacion();
public:
    SC_CTOR(OrGate);
    ~OrGate();

    sc_in<bool> aIn;  //puerto de entrada del modulo
    sc_in<bool> bIn;  //puerto de entrada del modulo
    sc_out<bool> cOut; //puerto de salida del modulo
};

#endif 