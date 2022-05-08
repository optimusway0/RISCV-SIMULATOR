#include "OrGate.h"
#include "Testbench.h"
#include <iostream>

using namespace std;

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName)
{
    SC_THREAD(prueba);
    sensitive << clkIn.pos();
}                

Testbench::~Testbench(){}

void Testbench::prueba()
{
    cout << "\nCOMPUERTA OR (simulacion)" << endl;
    cout << "a b c" << endl;

    //Se envian los estimulos
    for (size_t i = 0; i <= 1; i++)
    {
        for (size_t j = 0; j <= 1; j++)
        {
            aOut.write(i);
            bOut.write(j);
            wait();
            imprimir();
        }
    }

    sc_stop();
}

void Testbench::imprimir()
{
    cout << aOut.read() << " ";
    cout << bOut.read() << " ";
    cout << cIn.read() << endl;
}