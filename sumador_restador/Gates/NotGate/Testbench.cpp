#include "Testbench.h"
#include <iostream>

using namespace std;

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName)
{
    SC_THREAD(prueba);
    sensitive << clkIn.pos();
}

Testbench::~Testbench() {}

void Testbench::prueba() 
{
    cout << "\nCompuerta NOT" << endl;
    cout << "a b" << endl;

    for(size_t i = 0; i < 2; ++i) {
        
        aOut.write(i);
        wait();

        impresion();
    }
    
    sc_stop();
}

void Testbench::impresion()
{
    cout << aOut.read() << " ";
    cout << bIn.read() << endl;
}