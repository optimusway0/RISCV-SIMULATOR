#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>

class Testbench : public sc_module {

public:
    SC_CTOR(Testbench);

	sc_out<sc_uint<5>> opcodeOut; 
	sc_in<bool> RegWriteIn;              // indica si Registers tiene habilitada la escritura
	sc_in<bool> MemWriteIn, MemReadIn;   // indica si Data Memory tiene habilitada la escritura y lectura
	sc_in<bool> ALUSrcIn;                // indica al multiplexor si debe dejar pasar el ReadData 2 o el inmediato a la unidad ALU
	sc_in<sc_uint<5>> ALUOpIn;           // indica a la unidad ALU que operación realizar según el código de operación
	sc_in<bool> MemtoRegIn;              // indica al multiplexor si debe dejar pasar el ReadData del DataMemory o el resultado de la ALU al WriteData de Registers
	sc_in<bool> branchIn;                // indica si habrá instruccion de salto

    sc_in_clk clkIn;                       // señal de reloj

private:
	void test();
    void print();

};

#endif
