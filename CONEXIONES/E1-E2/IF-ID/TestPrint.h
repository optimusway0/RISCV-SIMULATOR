#include <systemc.h>
#ifndef TEST_PRINT_H
#define TEST_PRINT_H

class TestPrint : public sc_module
{
private:
   
public:
    sc_in<sc_uint<5>> opcodeIn;
    SC_CTOR(TestPrint);
    void print();    
};
#endif