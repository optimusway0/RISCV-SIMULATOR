#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
#include <systemc.h>

    class RegisterFile : public sc_module 
    {
    private:

        void operation(); 
        
    public:
        SC_CTOR(RegisterFile);
       
        
        sc_in<bool> weIn; 
        sc_out<sc_int<32>> aOut, bOut;
        sc_in<sc_int<32>> wIn;  
        sc_in<sc_int<5>> rwIn,raIn,rbIn;          
        
        sc_int<32> storage[15];//Solo llenare algunos valores por razones practicas, de prueba e implementacion

    };      

#endif