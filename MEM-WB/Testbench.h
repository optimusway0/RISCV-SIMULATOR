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

    sc_out<bool> weOut, reOut; //Señales de control

    sc_out< sc_uint<32> > dirOut;
    sc_out< sc_int<32> > wOut;
    sc_in< sc_int<32> > dataIn;
    sc_in<bool> clkIn;

};

#endif //TESTBENCH_H