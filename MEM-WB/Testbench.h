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

    sc_out< sc_int<32> > dirOut;
    sc_out< sc_int<32> > wOut;
    sc_in< sc_int<32> > wIn;
    sc_in<bool> clkIn;
    sc_out<bool> branchOut, mentoReg, zeroOut; //simulan las señales de control de la UC, y si la ALU valida o no un salto
    sc_in<bool> muxIfIn; //muxIfIn se usa para simular el mux de la primera etapa IF  

};

#endif //TESTBENCH_H