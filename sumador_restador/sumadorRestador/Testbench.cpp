#include "Testbench.h"

Testbench::Testbench(sc_module_name mn) : sc_module(mn)
{
    SC_THREAD(Test);
    sensitive << clkIn.pos();
    dont_initialize();
}

Testbench::~Testbench() { }

void Testbench::Test()
{
    int numA[] = {7, 41, 4, 125, 1};
    int numB[] = {7, 25, 2, -342, 1};
    std::cout << "Sumador/Restador (AddSub)\n" << std::endl;

    std::cout << "num1 + num2    Resultado    acarreo   overflow" << std::endl;

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << numA[i] << "      " << numB[i]<< "          ";

        aOut.write(numA[i]);
        bOut.write(numB[i]);

        controlOut.write(0); // (0 suma), (1 resta)
        
        wait();

        Print();
    }
    
    std::cout << "\nnum1 - num2    Resultado    acarreo   overflow" << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << numA[i] << "      " << numB[i]<< "          ";

        aOut.write(numA[i]);
        bOut.write(numB[i]);

        controlOut.write(1); // (0 suma), (1 resta)
        
        wait();

        Print();
    }
    
    sc_stop();
    
}

void Testbench::Print()
{
    std::cout << rIn.read() << "          " <<carryIn.read() << "       " << overflowIn.read() << std::endl;
    
}

