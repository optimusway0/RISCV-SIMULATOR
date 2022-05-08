#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class Testbench : public sc_module
{
private:
    void impresion();
    void prueba();
public:
    SC_CTOR(Testbench);
    ~Testbench();

    sc_out<bool> aOut;
    sc_in<bool> bIn;
    sc_in<bool> clkIn;
};

#endif //TESTBENCH_H