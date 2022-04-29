#ifndef MUX_H
#define MUX_H

#include <iostream>

#include <systemc.h>


class Mux: public sc_module {
public:
  sc_in< sc_int<32> > aIn;
  sc_in<bool> sIn;
  sc_out< sc_int<32> > aOut;

  SC_CTOR(Mux);
  ~Mux();

private:
  void operation();
};

#endif