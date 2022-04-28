#include "unidad_control.h"
#include <iostream>
using namespace std;

UnidadControl::UnidadControl(sc_module_name mn) : sc_module(mn) {
	SC_METHOD(obtener_operacion);
	sensitive << opcodeIn;
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

void UnidadControl::obtener_operacion() {


	ALUOpOut.write(opcodeIn.read()) ; // lo pasa tal como está

	// es un instruccíon de tipo R
	if (opcodeIn.read() >= ADD && opcodeIn.read() <= SRA) {
		ALUSrcOut.write(false);         // el 2d0 operando de la ALU será el 2do registro leido del AR
		MemtoRegOut.write(false);          // el valor enviado al AR será la salida del ALU 
		RegWriteOut.write(true);        // se escribe en el registro destino el valor presente en write data (habilita la escritura en AR)
		MemWriteOut.write(false);       // no se permite la escritura en DataMemory
		MemReadOut.write(false);        // no se permite la lectura en DataMemory 
		branchOut.write(false);         // sin saltos 
	
	// instruccion de tipo I
	} else if (opcodeIn.read() >= ADDI && opcodeIn.read() <= SRAI) {

	// instruccion de tipo L
	} else if (opcodeIn.read() == LW) {

	// instruccion de tipo S
	} else if (opcodeIn.read() == SW) {

	// instruccion de tipo 
	} else if (opcodeIn.read() >= BEQ && opcodeIn.read() <= BGE) {

	}
	else {
		cout << "Instruccion invalida, cerrando simulacion" << endl;
		sc_stop();
	}
}


