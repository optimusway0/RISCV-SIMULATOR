#include "XnorGate.h"

XnorGate::XnorGate(sc_module_name moduleName) : sc_module(moduleName)
{
    SC_METHOD(operacion);
    sensitive << aIn << bIn; // la 'operacion' se activara con el cambio de aIn o bIn
}

XnorGate::~XnorGate() {}

void XnorGate::operacion()
{
    //Se ejecuta la operacion or del modulo
    cOut.write( not( aIn.read() xor bIn.read() ) );
}