#include "AndGate_3.h"

AndGate_3::AndGate_3(sc_module_name mn) : sc_module(mn)
{
    SC_METHOD(Operation);
    sensitive << aIn << bIn << cIn;
}

AndGate_3::~AndGate_3() { }

void AndGate_3::Operation()
{
    dOut.write( (aIn.read() and bIn.read() ) and cIn.read() ); //hace la operacion and y escribe en la salida dOut
}