#ifndef XNOR_GATE_H
#define XNOR_GATE_H

#include <systemc.h>

class XnorGate : public sc_module {
private:
    void operacion();
public:
    SC_CTOR(XnorGate);
    ~XnorGate();

    sc_in<bool> aIn;  //puerto de entrada del modulo
    sc_in<bool> bIn;  //puerto de entrada del modulo
    sc_out<bool> cOut; //puerto de salida del modulo
};

#endif 