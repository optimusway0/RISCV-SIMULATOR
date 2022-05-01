#include "SignalExpand.h"


SignalExpand::SignalExpand(sc_module_name nm) : sc_module(nm){

    SC_METHOD(expand);
    sensitive << immIn;

}
void SignalExpand::expand(){
    //cout << "expande " << immIn.read() << endl;
    int a = immIn.read();
    immOut.write(a);

}