#include "PrintSignal.h"


    PrintSignal::PrintSignal(sc_module_name nm) : sc_module (nm){
        SC_THREAD(print);
        sensitive << immIn;
        dont_initialize();
    }


    void PrintSignal::print(){

        
        cout<<"Signal: extendido a 32:  "<<immIn.read()<<endl;


    }