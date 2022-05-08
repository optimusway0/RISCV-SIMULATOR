#ifndef XOR_GATE_H
#define XOR_GATE_H

#include <systemc.h>

class XorGate : public sc_module {
private:
    void operacion();
public:
    SC_CTOR(XorGate);
    ~XorGate();

    sc_in<bool> aIn;  //puerto de entrada del modulo
    sc_in<bool> bIn;  //puerto de entrada del modulo
    sc_out<bool> cOut; //puerto de salida del modulo
};

#endif 