#ifndef ALU_H
#define ALU_H

#include <systemc.h>

class Alu : public sc_module {
public:
	SC_CTOR(Alu);

	sc_in<sc_int<32>> aIn, bIn;   // datos a operar
	sc_in<sc_uint<5>> ALUOpIn;      // indica que operación va a realizar la ALU, UC indica este valor
	sc_out<sc_int<32>> aluResultOut; // wOut
	sc_out<bool> zeroSg;

private:
	void operation();

};

#endif