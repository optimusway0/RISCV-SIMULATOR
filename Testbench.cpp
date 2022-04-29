#include "Testbench.h"
#include <iomanip>

Testbench::Testbench(sc_module_name mn) : sc_module(mn)
{
    SC_THREAD(Test);
    sensitive << clkIn;
}

Testbench::~Testbench() {}

void Testbench::Test(){
    std::cout << "Tiempo    jump      rd      rs1     rs2     imm     opcode\n";
    std::cout << "-----------------------------------------------------------\n";

    for(int i = 0; i < 50; i++){
        wait();
        Print();
    }

    sc_stop();
}

void Testbench::Print(){

    std::cout << std::setw(6) << sc_time_stamp();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << jump.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << rd.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << rs1.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << rs2.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << imm.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << opcode.read();
    std::cout << std::setw(4) << "" << std::endl;   
}