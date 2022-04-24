#include "Testbench.h"
#include <iomanip>

Testbench::Testbench(sc_module_name mn) : sc_module(mn)
{
    SC_THREAD(Test);

    sensitive << clkIn;
    dont_initialize();
}

Testbench::~Testbench() {}

void Testbench::Test()
{
    int numbers[] = {12, 14, 32, 22};
    int adresses[] = {0, 4, 8, 16};

    for(int i = 0; i<4; i++) 
    {
        weOut.write(1);
        reOut.write(0);

        dirOut.write(adresses[i]);
        wOut.write(numbers[i]);

        wait();
        wait();
        wait();
    }

    std::cout << "Tiempo    weIn   reIn   clkIn     dataIn\n";
    
    for(int i = 0; i<4; i++)
    {
        weOut.write(0);
        reOut.write(1);

        dirOut.write(adresses[i]);

        wait();
        wait();
        wait();

        Print();
    }

    sc_stop();
}

void Testbench::Print()
{
    std::cout << std::setw(6) << sc_time_stamp();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << weOut.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << reOut.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << clkIn.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << dataIn.read() << std::endl;   
}