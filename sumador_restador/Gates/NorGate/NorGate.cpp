#include "NorGate.h"

NorGate::NorGate(sc_module_name moduleName) : sc_module(moduleName)
{
    SC_METHOD(operacion); //Constructor
    sensitive << aIn << bIn; //la 'operacion' se activara con el cambio de aIn o bIn
}

NorGate::~NorGate() {}

void NorGate::operacion()
{
    //Se ejecuta la operacion or del modulo
    cOut.write( not(aIn.read() or bIn.read()) );
}