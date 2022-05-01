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

	bool none = false; // variable para indicar que no importa el valor que se le pase no será usado


	ALUOpOut.write(opcodeIn.read()) ; // lo pasa tal como está

	// es un instruccíon de tipo R
	if (opcodeIn.read() >= ADD && opcodeIn.read() <= SRA) {
		ALUSrcOut.write(true);         // el 2do operando de la ALU será el 2do registro leido del AR
		MemtoRegOut.write(true);       // el valor enviado al AR será la salida del ALU 
		RegWriteOut.write(true);        // se escribe en el registro destino el valor presente en write data (habilita la escritura en AR)
		MemWriteOut.write(false);       // no se permite la escritura en DataMemory
		MemReadOut.write(false);        // no se permite la lectura en DataMemory 
		branchOut.write(false);         // sin saltos 
	 
	// instruccion de tipo I
	} else if (opcodeIn.read() >= ADDI && opcodeIn.read() <= SRAI) {
		ALUSrcOut.write(false);          // el 2do operando de la ALu será el valor inmediato
		MemtoRegOut.write(true);       // el valor enviado al AR será la salida del ALU
		RegWriteOut.write(true);        // se escribe en el registro destino el valor presente en write data
		MemWriteOut.write(false);       // no se permite la escritura en DataMemory
		MemReadOut.write(false);       // no se permite la lectura en DataMemory
		branchOut.write(false);         // sin saltos

	// instruccion de tipo L
	} else if (opcodeIn.read() == LW) {
		ALUSrcOut.write(false);          // el 2do operando de la ALu será el valor inmediato
		MemtoRegOut.write(false);        // el valor enviado al AR será el que arroje la DM (dataOut) 
		RegWriteOut.write(true);        // se escribe en el registro destino el valor presente en write data
		MemWriteOut.write(false);       // no se permite la escritura en DataMemory
		MemReadOut.write(true);         // permite la lectura en DataMemory
		branchOut.write(false);         // sin saltos

	// instruccion de tipo S
	} else if (opcodeIn.read() == SW) {
		ALUSrcOut.write(false);         // el 2do operando de la ALu será el valor inmediato 
		MemtoRegOut.write(none);       // no se enviará al AR (no importa que valor se envie, no se usará)
		RegWriteOut.write(false);      // no se permite la escritura en el registro AR
		MemWriteOut.write(true);       // se permite la escritura en DataMemory
		MemReadOut.write(false);       // no se permite la lecutra en DataMemory
		branchOut.write(false);        // sin saltos


	// instruccion de tipo salto
	} else if (opcodeIn.read() >= BEQ && opcodeIn.read() <= BGE) {
		cout << "UnidadControl llama un salto \n";
		ALUSrcOut.write(true);         // el 2do operando de la ALu será el 2do registro leído del AR
		MemtoRegOut.write(none);       // no se enviará al AR (no importa que valor se envie, no se usará)
		RegWriteOut.write(false);      // no se permite la escritura en el registro AR
		MemWriteOut.write(false);       // no se permite la escritura en DataMemory
		MemReadOut.write(false);       // no se permite la lecutra en DataMemory
		branchOut.write(true);        // con saltos

	}
	else {
		//cout << "Instruccion invalida, cerrando simulacion" << endl;
		//sc_stop();
	}
}


