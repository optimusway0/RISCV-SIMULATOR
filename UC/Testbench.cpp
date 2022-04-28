#include "Testbench.h"
#include <iostream>
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
	cout << sc_time_stamp() << "\t      "
	     << opcodeOut.read() << "\t\t"
	     << ALUSrcIn.read() << "\t"
	     << MemtoRegIn.read() << "\t"
	     << RegWriteIn.read() << "\t"
	     << MemReadIn.read() << "\t  "
	     << MemWriteIn.read() << "\t   "
	     << branchIn.read() << "\n";
}


void Testbench::test() {

	cout << "Tiempo     opcode  ALUSrc  MemtoReg  RegWrite  MemRead  MemWrite  Branch\n"
	     << "---------------------------------------------------------------------\n";

	// test 1 instruccion de tipo R (add)
	opcodeOut.write(ADD);
	wait();
	print();

	// test 2 instruccion de tipo R (XOR)
	opcodeOut.write(XOR);
	wait();
	print();


	sc_stop();
}