#ifndef NOR_GATE_H
#define NOR_GATE_H

#include <systemc.h>

class NorGate : public sc_module {
private:
    void operacion();
public:
    SC_CTOR(NorGate);
    ~NorGate();

    sc_in<bool> aIn;  //puerto de entrada del modulo
    sc_in<bool> bIn;  //puerto de entrada del modulo
    sc_out<bool> cOut; //puerto de salida del modulo
};

#endif 