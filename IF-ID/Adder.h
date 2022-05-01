#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Adder : public sc_module {
  public:
    sc_in< sc_int<32> > aIn, bIn;   //puerto de entrada del modulo
    sc_out<sc_int<32> > aOut; //puerto de salida del modulo

    SC_CTOR(Adder);
    ~Adder(); 
  private:
    void operation();
};

#endif