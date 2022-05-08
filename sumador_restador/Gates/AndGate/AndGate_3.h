#ifndef AND_GATE_3_H
#define AND_GATE_3_H

#include <systemc.h>

class AndGate_3 : public sc_module
{
private:
    void Operation();
public:
    SC_CTOR(AndGate_3);
    ~AndGate_3();

    sc_in<bool> aIn, bIn, cIn;
    sc_out<bool> dOut;
};

#endif //AND_GATE_3_H