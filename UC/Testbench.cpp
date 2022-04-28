#include "Testbench.h"
#include <iostream>
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
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
	cout << setw(6) << sc_time_stamp() << "   "
	     << setw(6) << opcodeOut.read() << "   "
	     << setw(6) << ALUSrcIn.read() << "  "
	     << setw(6) << MemtoRegIn.read() << "   "
	     << setw(6) << RegWriteIn.read() << "  "
	     << setw(6) << MemReadIn.read() << "   "
	     << setw(6) << MemWriteIn.read() << "   "
	     << setw(6) << branchIn.read() << "\n";
}


void Testbench::test() {

	cout << "Tiempo     opcode  ALUSrc  MemtoReg  RegWrite  MemRead  MemWrite  Branch\n"
	     << "---------------------------------------------------------------------\n";

  int instruction[] = {ADD, XOR, ADDI, LW, SW};

  for (int i : instruction) {
    opcodeOut.write(i);
    wait();
    print();
  }


	sc_stop();
}