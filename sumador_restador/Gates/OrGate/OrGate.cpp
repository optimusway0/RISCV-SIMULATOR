#include "OrGate.h"

OrGate::OrGate(sc_module_name moduleName) : sc_module(moduleName)
{
    SC_METHOD(operacion);
    sensitive << aIn << bIn; // la 'operacion' se activara con el cambio de aIn o bIn
}

OrGate::~OrGate() {}

void OrGate::operacion()
{
    //Se ejecuta la operacion or del modulo
    cOut.write( aIn.read() or bIn.read() );
}