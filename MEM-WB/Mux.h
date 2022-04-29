#ifndef MUX_H
#define MUX_H

#include <systemc.h>

class Mux: public sc_module {
public:
  
  sc_in< sc_int<32> > aIn, bIn;
  sc_in<bool> s0In;
  sc_out< sc_int<32> > cOut;

  SC_CTOR(Mux);

private:
  
  void operation();
};

#endif