#include "MuxEX.h"

MuxEX::MuxEX(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << aIn << bIn << s0In;
}

void MuxEX::operation() {
  cout << " y el mux lee " << aIn.read() << " y " << bIn.read() << endl;

  if (s0In.read())            
    cOut.write(aIn.read()); // se deja pasar el primer elemento 
  else 
    cOut.write(bIn.read()); // se deja pasar el segundo elemento
  
}
