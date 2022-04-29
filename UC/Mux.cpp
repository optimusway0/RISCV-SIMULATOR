#include "Mux.h"


Mux::Mux(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << s0In << aIn << bIn;
}

void Mux::operation() {
  
  if (s0In.read())            
    cOut.write(aIn.read()); // se deja pasar el primer elemento 
  else 
    cOut.write(bIn.read()); // se deja pasar el segundo elemento
  
}
