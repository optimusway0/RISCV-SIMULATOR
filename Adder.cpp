#include "Adder.h"

Adder::Adder(sc_module_name moduleName) : sc_module(moduleName) {
  SC_METHOD(operation);
  sensitive << aIn << bIn;
}

Adder::~Adder() {}

void Adder::operation() {
  aOut.write(aIn.read() + bIn.read());
}