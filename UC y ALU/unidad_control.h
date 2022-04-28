#ifndef UNIDAD_CONTROL_H
#define UNIDAD_CONTROL_H

#include <systemc.h>

class UnidadControl : public sc_module {
public:
	SC_CTOR(UnidadControl);

	sc_in<sc_uint<5>> opcodeIn;
	sc_out<bool> werOut; //weOut, reOut;   // señales de control que indica si es posible la escritura en un archivo.
	sc_out<sc_uint<5>> aluOpOut;         // indica a la unidad ALU que operación realizar según el código de operación

private:
	void obtener_operacion();

};

#endif	