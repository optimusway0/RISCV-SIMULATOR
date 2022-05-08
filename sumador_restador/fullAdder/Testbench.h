#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class Testbench : public sc_module
{
private:
    void Test();
    void Print();
public:
    SC_CTOR(Testbench);
    ~Testbench();

    sc_in<bool> rIn, carryIn, clkIn;
    sc_out<bool> carryOut, aOut, bOut;
};

#endif //TESTBENCH_H

