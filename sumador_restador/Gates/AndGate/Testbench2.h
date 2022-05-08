#ifndef TESTBENCH2_H
#define TESTBENCH2_H

#include <systemc.h>

class Testbench2 : public sc_module
{
private:
    void print();
    void test();
public:
    SC_CTOR(Testbench2);
    ~Testbench2();

    sc_in<bool> dIn;
    sc_out<bool> aOut;
    sc_out<bool> bOut;
    sc_out<bool> cOut;
    sc_in<bool> clkIn;

};

#endif //TESTBENCH2_H

