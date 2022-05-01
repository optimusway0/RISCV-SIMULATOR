#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
#include <systemc.h>

    class RegisterFile : public sc_module 
    {
    private:
        void operation(); 
    public:
        SC_CTOR(RegisterFile);
        
        sc_in<bool> weIn;          //Habilitador de escritura.
        sc_in<sc_int<32>> wIn;    // Lo que regresa del Write back      

        sc_in< sc_uint<5> > rd;
        sc_in< sc_uint<5> > rs1;
        sc_in< sc_uint<5> > rs2;  
        sc_out<sc_int<32>> aOut, bOut;     //Salidas estas son de los datos que ya estan registrados en storage
        sc_in<bool> clkIn;
        sc_int<32> storage[30];//Hace referencia del 0/31
    };      

#endif