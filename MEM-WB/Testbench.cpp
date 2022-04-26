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
    int numbers[] = {12, -14, 32, -22}; //valores que seran guardadas en la memoria de datos
    int adresses[] = {0, 4, 8, 16}; // Direcciones a utilizar

    //Simulamos que primero se guardan  datos en memoria
    for(int i = 0; i<4; i++) 
    {
        weOut.write(1);

        dirOut.write(adresses[i]);
        wOut.write(numbers[i]);

        wait();
    }

    std::cout << "Tiempo    weIn   clkIn     dataIn\n";
    //Simulamos que se leen esos datos previamente guardados
    for(int i = 0; i<4; i++)
    {
        weOut.write(0);

        dirOut.write(adresses[i]);
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
    std::cout << std::setw(4) << clkIn.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << dataIn.read() << std::endl;   
}