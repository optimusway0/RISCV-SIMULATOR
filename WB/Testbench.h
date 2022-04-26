#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in<bool> clkIn;
  sc_in< sc_int<32> > cIn;
  sc_out<bool> s0Out;
  sc_out<sc_int<32> > aOut, bOut;

  SC_CTOR(Testbench);

private:
  void print(bool);
  void test();
};

#endif
