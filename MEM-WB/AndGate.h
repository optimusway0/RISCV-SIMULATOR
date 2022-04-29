#ifndef ANDGATE_H
#define ANDGATE_H

#include <systemc.h>

class AndGate : public sc_module {
public:
  sc_in<bool> aIn, bIn;//, cIn;
  sc_out<bool> dOut;

  SC_CTOR(AndGate);

private:
  void operation();
};

#endif