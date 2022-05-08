#include "Testbench2.h"

Testbench2::Testbench2(sc_module_name mn) : sc_module(mn)
{
    SC_THREAD(test);
    sensitive << clkIn;
}

Testbench2::~Testbench2() { }

void Testbench2::test()
{
    std::cout << "aIn   bIn   cIn   |dOut" << std::endl;

    for (size_t i = 0; i < 2; i++)
    {
        aOut.write(i);
        for (size_t j = 0; j < 2; j++)
        {
            bOut.write(j);
            for (size_t k = 0; k < 2; k++)
            {
                cOut.write(k);
                wait();

                print();
            }
            
        }
        
    }

    sc_stop();
    
}

void Testbench2::print()
{
    std::cout << aOut.read() << "   " << bOut.read() << "   " << cOut.read() << "   " << dIn.read() << std::endl;
}