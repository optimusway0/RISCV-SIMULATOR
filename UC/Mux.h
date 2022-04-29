
#ifndef MUX_H
#define MUX_H

#include <systemc.h>

class Mux: public sc_module {
public:
  
  sc_in< sc_int<32> > aIn, bIn; // dato de entrada 1 y 2 respectivamente
  sc_in<bool> s0In;             // señal que indicará cual valor pasar     
  sc_out< sc_int<32> > cOut;    // dato de salida

  SC_CTOR(Mux);

private:
  
  void operation();
};

#endif
