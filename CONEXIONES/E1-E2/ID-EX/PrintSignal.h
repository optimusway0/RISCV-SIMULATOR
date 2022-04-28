#ifndef PRINT_SIGNAL_H
#define PRINT_SIGNAL_H

#include<systemc.h>

    
    class PrintSignal : public sc_module
    {
    
    public:
        SC_CTOR(PrintSignal);
        sc_in<sc_int<32>> immIn;
        
    private:
        void print();
        
    };
    
    




#endif