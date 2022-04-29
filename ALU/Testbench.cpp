#include "Testbench.h"
#include <iostream>
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn)
{
    SC_THREAD(test);
    sensitive << clkIn; //debe trabajar con con el franco de bajada de reloj pero no recuerdo cual es su valor
    dont_initialize();
}

enum Instructions {
  INVALID,
  ADD,
  SUB,
  AND,
  OR,
  XOR,
  SLT,
  SLTU,
  SLL,
  SRL,
  SRA,
  ADDI,
  ANDI,
  ORI,
  XORI,
  SLTI,
  SLTUI,
  SLLI,
  SRLI,
  SRAI,
  LW,
  SW,
  BEQ,
  BNE,
  BLT,
  BGE
};

void Testbench::print() {
    cout << setw(6) << sc_time_stamp() << "  "
         << setw(5) << ALUOpOut.read() << "  "
         << setw(4) << aOut.read() << " "
         << setw(4) << bOut.read() << " "
         << setw(4) << aluResultIn.read() << "\n"; 
}

void Testbench::test() {

    cout << "Tiempo  aluOpOut  a   b  result" << endl;
    cout << "-------------------------------" << endl;

    // test 1: suma de dos enteros
    ALUOpOut.write(ADD);
    aOut.write(2);
    bOut.write(4);
    wait();
    print();

    // test_2: resta de dos enteros
    ALUOpOut.write(SUB);
    aOut.write(5);
    bOut.write(3);
    wait();
    print();

    sc_stop();
}