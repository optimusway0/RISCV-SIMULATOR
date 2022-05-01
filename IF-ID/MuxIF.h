#ifndef MUXIF_H
#define MUXIF_H

#include <iostream>

#include <systemc.h>


class MuxIF: public sc_module {
public:
  sc_in< sc_int<32> > aIn;
  sc_in<bool> sIn;
  sc_out< sc_int<32> > aOut;
  
  SC_CTOR(MuxIF);
  ~MuxIF();

private:
  void operation();
};

#endif