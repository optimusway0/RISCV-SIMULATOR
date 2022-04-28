#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Adder : public sc_module {
  public:
    sc_in< sc_uint<32> > aIn;   //puerto de entrada del modulo
    sc_out<sc_uint<32> > aOut; //puerto de salida del modulo

    SC_CTOR(Adder);
    ~Adder(); 
  private:
    void operation();
};

#endif