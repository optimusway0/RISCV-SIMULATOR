#ifndef SIGNAL_EXPAND_H
#define SIGNAL_EXPAND_H
#include <systemc.h>

class SignalExpand : public sc_module
{
private:
   
public:

    SC_CTOR(SignalExpand);
    sc_in<sc_int<12>> immIn;
    sc_out<sc_int<32>> immOut;  

    void expand();

};








#endif