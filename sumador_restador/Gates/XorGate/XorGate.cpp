#include "XorGate.h"

XorGate::XorGate(sc_module_name moduleName) : sc_module(moduleName)
{
    SC_METHOD(operacion);
    sensitive << aIn << bIn; // la 'operacion' se activara con el cambio de aIn o bIn
}

XorGate::~XorGate() {}

void XorGate::operacion()
{
    //Se ejecuta la operacion or del modulo
    cOut.write( aIn.read() xor bIn.read() );
}