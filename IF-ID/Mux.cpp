#include "Mux.h"


Mux::Mux(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << sIn << aIn;
}

void Mux::operation() {
  if(sIn){
    aOut.write(aIn);
  } else{
    aOut.write(4);
  }
}

Mux::~Mux() {}
