#ifndef TESTBENCH_H 
#define TESTBENCH_H 

#include <systemc.h>

class Testbench : public sc_module {
       
    public:
    //Por cada puerto de entrada de la compuerta abra un puerto de salida, y por cada puerto de 
    //salida abra uno de entrada;
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