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
        reOut.write(0);

        dirOut.write(adresses[i]);
        wOut.write(numbers[i]);

        wait();
    }

    std::cout << "Tiempo    weIn   reIn    clkIn     wIn    branchOut    zeroOut    muxIfIn \n";
    //Simulamos que se leen esos datos previamente guardados
    //con la instruccion lw
    for(int i = 0; i<4; i++)
    {
        weOut.write(0);
        reOut.write(1);
        mentoReg.write(0); // simulamos que la unidad de control manda una señal de 1
        
        //Simulamos si se aprueban o no los saltos
        branchOut.write(i);
        zeroOut.write(i);

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
    std::cout << std::setw(4) << reOut.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << clkIn.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << wIn.read();
    std::cout << std::setw(4) << " | ";
    std::cout << std::setw(4) << branchOut.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(8) << zeroOut.read();
    std::cout << std::setw(8) << "";
    std::cout << std::setw(6) << muxIfIn.read() << std::endl;  
}