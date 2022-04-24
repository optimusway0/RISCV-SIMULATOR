#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <systemc.h>

class DataMemory : public sc_module
{
private:
    void Read();
    void Write();
public:
    SC_CTOR(DataMemory);
    ~DataMemory();

    sc_in<sc_uint<32> > dirIn;
    sc_in< sc_uint<32> > wIn;
    sc_out< sc_uint<32> > dataOut; 
    sc_in<bool> weIn, reIn; //Señales de control  

    sc_in<bool> clkIn;

    sc_uint<8> storage[32];

};

#endif //DATA_MEMORY_H
