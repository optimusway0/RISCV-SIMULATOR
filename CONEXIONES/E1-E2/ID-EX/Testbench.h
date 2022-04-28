#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
  
  //sc_out<sc_int<5>> rwOut, raOut,rbOur;
  sc_in_clk clk;
  sc_out<bool> weOut;
  
  sc_out<sc_uint<5>> rwOut, raOut, rbOut;
  sc_in<sc_int<32>> aIn, bIn;
  sc_out<sc_int<32>> wOut;

  

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
