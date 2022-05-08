#include "NotGate.h"

NotGate::NotGate(sc_module_name moduleName) : sc_module(moduleName)
{
    SC_METHOD(complementar);
    sensitive << aIn;
}

NotGate::~NotGate() {}

void NotGate::complementar()
{
    bOut.write( not ( aIn.read() ) ); // complementamos la entrada (La negamos)
}