#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

#include <systemc.h>

class ProgramCounter : public sc_module {
  public:
    sc_in< sc_int<32> > aIn;   //puerto de entrada del modulo
    sc_out<sc_int<32> > aOut; //puerto de salida del modulo

    sc_in<bool> clkIn;

    sc_int<32> number;

    SC_CTOR(ProgramCounter);
    ~ProgramCounter(); 
  private:
    void operation();
};

#endif