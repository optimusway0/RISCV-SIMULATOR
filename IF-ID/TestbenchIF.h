#include <systemc.h>

#ifndef TESTBENCH_IF_H
#define TESTBENCH_IF_H

class TestbenchIF : public sc_module
{
private:
    void Test();
    void Print();
public:
    SC_CTOR(TestbenchIF);
    ~TestbenchIF();

    sc_in< sc_int<32> > pc;
    sc_in< sc_int<32> > rs1;
    sc_in< sc_int<32> > rs2;
    sc_in< sc_int<32> > imm;
    sc_in< sc_int<32> > result;
    sc_in< sc_uint<5> > opcode;

    sc_in<bool> clkIn;

};

#endif