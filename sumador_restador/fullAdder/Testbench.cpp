#include "Testbench.h"

Testbench::Testbench(sc_module_name mn) : sc_module(mn)
{
    SC_THREAD(Test);
    sensitive << clkIn.pos();
    dont_initialize();
}

Testbench::~Testbench()
{
}

void Testbench::Test()
{
    std::cout << "\ncarryIn    aIn   bIn   resultOut   carryOut" << std::endl;

    for (size_t i = 0; i < 2; i++)
    {
        carryOut.write(i);
        for (size_t j = 0; j < 2; j++)
        {
            aOut.write(j);
            for (size_t k = 0; k < 2; k++)
            {
                bOut.write(k);
                wait();
                Print();
            }   
        }
    }
    
    sc_stop();
}

void Testbench::Print()
{
    std::cout << carryOut.read() << "           " << aOut.read() << "     " << bOut.read() << "        " << rIn.read() << "            " << carryIn.read() << std::endl;
}

/*Tabla de verdad de un FUll ADDER (COMPARAR CON EL RESULTADO DEL PROGRAMA)
    cIn|A|B| Result | Cout
    0   0 0     0       0
    0   0 1     1       0
    0   1 0     1       0
    0   1 1     0       1
    1   0 0     1       0
    1   0 1     0       1
    1   1 0     0       1
    1   1 1     1       1


*/