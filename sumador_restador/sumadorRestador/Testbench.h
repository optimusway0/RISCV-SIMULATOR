#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include "AddSub.h"

class Testbench : public sc_module
{
private:
    void Test();
    void Print();
public:
    SC_CTOR(Testbench);
    ~Testbench();

    sc_out< sc_int<ADD_SUB_BITS> > aOut, bOut;
    sc_out<bool> controlOut;
    sc_in<bool> carryIn, overflowIn, clkIn;
    sc_in< sc_int<ADD_SUB_BITS> > rIn;

};

#endif //TESTBENCH_H