#include "TestbenchIF.h"
#include <iomanip>

TestbenchIF::TestbenchIF(sc_module_name mn) : sc_module(mn)
{
    SC_THREAD(Test);
    sensitive << clkIn;
}

TestbenchIF::~TestbenchIF() {}

void TestbenchIF::Test(){
    //std::cout << "Tiempo      pc   result      rs1     rs2     imm     opcode\n";
    //std::cout << "-----------------------------------------------------------\n";


    for(int i = 0; i < 20; i++){
        wait();
        //Print();
    }

    sc_stop();
}

void TestbenchIF::Print(){

    std::cout << std::setw(6) << sc_time_stamp();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << pc.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << result.read();
    std::cout << std::setw(8) << "";
    std::cout << std::setw(4) << rs1.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << rs2.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << imm.read();
    std::cout << std::setw(4) << "";
    std::cout << std::setw(4) << opcode.read();
    std::cout << std::setw(4) << "" << std::endl;   
}