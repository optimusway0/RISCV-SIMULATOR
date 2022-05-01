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
	switch (ALUOpIn.read()) {
		// instrucciones de tipo R 
		case ADD:
		case ADDI:
			aluResultOut.write(aIn.read() + bIn.read());
		break;
		case SUB:
			aluResultOut.write(aIn.read() - bIn.read());
		break;
		case AND:
		case ANDI:
			aluResultOut.write(aIn.read() && bIn.read());
		break;
		case OR:
		case ORI:
			aluResultOut.write(aIn.read() || bIn.read());
		break;
		case XOR:
		case XORI:
			aluResultOut.write( (!aIn.read() && bIn.read()) || (aIn.read() && !bIn.read()) );
		break;
		case SLT:
  	case SLTU:
  	case SLTI:
  	case SLTUI:
  		aluResultOut.write((aIn.read() < bIn.read()) ? 1 : 0);
  	break;
  	case SLL:
  	case SLLI:
  		aluResultOut.write(aIn.read() << bIn.read());
  	break;
  	case SRL:
  	case SRLI:
  	case SRA:
  	case SRAI:
  		aluResultOut.write(aIn.read() >> bIn.read());
  	break;
  	case BEQ:
  		zeroSg.write(aIn.read() == bIn.read());  
  	break;
   	case BLT:
   		zeroSg.write(aIn.read() < bIn.read());
   	break;
  	case BNE:
  		zeroSg.write(aIn.read() != bIn.read());  
  	break;			
		default:
      return;
		break;
	}
}

