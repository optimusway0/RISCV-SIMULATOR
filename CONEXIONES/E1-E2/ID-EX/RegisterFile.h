#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
#include <systemc.h>

    class RegisterFile : public sc_module 
    {
    private:

        void operation(); 
        
    public:
        SC_CTOR(RegisterFile);
       
        
        //sc_in<bool> weIn;          //Habilitador de escritura.
       // sc_int<32> aOut, bOut;     //Salidas estas son de los datos que ya estan registrados en storage
        //sc_in<sc_uint<32>> wIn;    // LO que regresa del Write back
        sc_in<sc_uint<5>> rwIn,raIn,rbIn;          
        sc_in<bool> clkIn;
        sc_uint<32> storage[30];//Hace referencia del 0/31

    };      

#endif