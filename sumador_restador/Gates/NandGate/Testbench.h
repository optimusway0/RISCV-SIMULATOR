#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class Testbench : public sc_module {
  public:
    /* Por cada puerto de salida del módulo a probar, el testbench debe tener un puerto de entrada del mismo tipo.
     * Por cada puerto de entrada del módulo a probar, el testbench debe tener un puerto de salida del mismo tipo.
     * */
    sc_in<bool> cIn;
    sc_out<bool> aOut;
    sc_out<bool> bOut;
    sc_in<bool> clkIn; //El testbench siempre deberá tener ésta entrada para el reloj.

    // Construtor del módulo testbench
    SC_CTOR(Testbench);
    ~Testbench();
  private:
    void print();
    void test();
};

#endif