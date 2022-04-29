#include "alu.h"
#include <iostream>

Alu::Alu(sc_module_name nm) : sc_module(nm) {
	SC_METHOD(operation);
	sensitive << aIn << bIn << ALUOpIn;
	dont_initialize();
}

// temporal, son las constantes de los tipos de instruccion
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

void Alu::operation() {
	//std::cout << "alu realizando una operacion: " << ALUOpIn.read() << std::endl; // debug
	switch (ALUOpIn.read()) {
		// instrucciones de tipo R 
		case ADD:
			aluResultOut.write(aIn.read() + bIn.read());
		break;
		case SUB:
			aluResultOut.write(aIn.read() - bIn.read());
		break;
		case AND:
			aluResultOut.write(aIn.read() && bIn.read());
		break;
		case OR:
			aluResultOut.write(aIn.read() || bIn.read());
		break;
		case XOR:
			aluResultOut.write( ! aIn.read() && bIn.read() || aIn.read() && ! bIn.read());
		break;
		case SLT:
  		case SLTU:
  		case SLL:
  		case SRL:
  		case SRA:
  		break;
  		// instrucciones de tipo I etc
		default:
			std::cout << "Instruccion invalida, por lo tanto finaliza la simulación" << std::endl;
			sc_stop(); // instruccion invalida (no debeŕia entrar aquí)
      	return;
		break;
	}

}

