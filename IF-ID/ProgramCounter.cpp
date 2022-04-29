#include "ProgramCounter.h"

ProgramCounter::ProgramCounter(sc_module_name moduleName) : sc_module(moduleName) {
  number = 0;

  SC_METHOD(operation);
  sensitive << clkIn;
}

ProgramCounter::~ProgramCounter(){}

void ProgramCounter::operation() {
  number = aIn.read();
  aOut.write(number);
}