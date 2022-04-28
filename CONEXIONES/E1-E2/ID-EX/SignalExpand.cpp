#include "SignalExpand.h"


SignalExpand::SignalExpand(sc_module_name nm) : sc_module(nm){

    SC_METHOD(expand);
    sensitive <<immIn;
    dont_initialize();

}
void SignalExpand::expand(){

    int a = immIn.read();
    immOut.write(a);

}