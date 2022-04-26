#include "Mux.h"


Mux::Mux(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << s0In << aIn << bIn;
}

void Mux::operation() {
  
  if (s0In.read()) // Si el bit de selección es 1, entonces seleccionará la segunda entrada de datos.
    cOut.write(bIn.read());
  else // Si el bit de selección no es 1, es 0, entonces seleccionará la primera entrada de datos.
    cOut.write(aIn.read());
  
}
