#include "unidad_control.h"
#include <iostream>
using namespace std;

UnidadControl::UnidadControl(sc_module_name mn) : sc_module(mn) {
	SC_METHOD(obtener_operacion);
	sensitive << opcodeIn;
	dont_initialize();
}


void UnidadControl::obtener_operacion() {

	cout << "valor de opcodeIn: " << opcodeIn.read() << endl; // debug
	cout << "valor de aluOpOut: " << aluOpOut.read() << endl; // debug

	aluOpOut.write(opcodeIn.read()); // lo pasa tal como está
	werOut.write(1); // por ahora simplemente habilita la escritura para todo

}