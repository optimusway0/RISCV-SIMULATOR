#ifndef TESTBENCH_H 
#define TESTBENCH_H 

#include <systemc.h>

class Testbench : public sc_module {
       
    public:
    //Por cada puerto de entrada de la compuerta abra un puerto de salida en el Testbench, y por cada puerto de 
    //salida abra uno de entrada en el Testbench;
    sc_out <bool> aOut;
    sc_out <bool> bOut;
    sc_in<bool> cIn;
    sc_in <bool> clkIn; 
    
    SC_CTOR(Testbench);
    ~Testbench();

    private:
        void imprimir();
        void prueba();
};

#endif