
#ifndef MUXEX_H
#define MUXEX_H

#include <systemc.h>

class MuxEX: public sc_module {
public:
  
  sc_in< sc_int<32> > aIn, bIn; // dato de entrada 1 y 2 respectivamente
  sc_in<bool> s0In;             // señal que indicará cual valor pasar     
  sc_out< sc_int<32> > cOut;    // dato de salida

  SC_CTOR(MuxEX);

private:
  
  void operation();
};

#endif
