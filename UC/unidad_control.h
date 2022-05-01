#ifndef UNIDAD_CONTROL_H
#define UNIDAD_CONTROL_H

#include <systemc.h>

class UnidadControl : public sc_module {
	
public:
	SC_CTOR(UnidadControl);

	sc_in<sc_uint<5>> opcodeIn; 
	sc_out<sc_uint<5>> ALUOpOut;           // indica a la unidad ALU que operación realizar según el código de operación
	sc_out<bool> RegWriteOut;              // indica si Registers tiene habilitada la escritura
	sc_out<bool> MemWriteOut, MemReadOut;  // indica si Data Memory tiene habilitada la escritura y lectura
	sc_out<bool> ALUSrcOut;                // indica al multiplexor si debe dejar pasar el ReadData 2 o el inmediato a la unidad ALU
	sc_out<bool> branchOut;                // indica si habrá instruccion de salto
	sc_out<bool> MemtoRegOut;              // indica al multiplexor si debe dejar pasar el ReadData del DataMemory o el resultado de la ALU al WriteData de Registers

private:
	void obtener_operacion();
};

#endif	