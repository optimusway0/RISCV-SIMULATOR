#include "TestPrint.h"


TestPrint::TestPrint(sc_module_name mn) : sc_module(mn){

    SC_THREAD(print);
    sensitive << opcodeIn;
    dont_initialize();
}



void TestPrint::print(){
    cout<<"Opcode: "<<opcodeIn.read() <<endl;
}

