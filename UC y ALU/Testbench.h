#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class Testbench : public sc_module {

public:
    SC_CTOR(Testbench);

    sc_out<sc_int<32>> aOut, bOut;  
    sc_out<sc_uint<5>> opcodeOut;      
    sc_in<sc_int<32>> aluResultIn;
    sc_in<bool> werIn;
    sc_in_clk clkIn; 

private:
    void test();
    void print();

};

#endif //TESTBENCH_H