#include "AndGate.h"

AndGate::AndGate(sc_module_name mn) : sc_module(mn) {
  SC_METHOD(operation);
  sensitive << aIn << bIn; //<< cIn;
}

void AndGate::operation() {
  dOut.write( aIn.read() and bIn.read() );
}