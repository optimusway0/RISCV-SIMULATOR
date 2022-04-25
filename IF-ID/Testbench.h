#include <systemc.h>

#ifndef TESTBENCH_H
#define TESTBENCH_H

class Testbench : public sc_module
{
private:
    void Test();
    void Print();
public:
    SC_CTOR(Testbench);
    ~Testbench();

    sc_out< sc_uint<32> > counterIn; //Contador de Programa

    sc_in< sc_uint<5> > rd;
    sc_in< sc_uint<5> > rs1;
    sc_in< sc_uint<5> > rs2;
    sc_in< sc_int<12> > imm;

    sc_in< sc_uint<5> > opcode;

    sc_in<bool> clkIn;

};

#endif //TESTBENCH_H