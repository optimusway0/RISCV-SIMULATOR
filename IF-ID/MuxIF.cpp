#include "MuxIF.h"


MuxIF::MuxIF(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << sIn << aIn;
}

void MuxIF::operation() {
  if(sIn){
    aOut.write(aIn);
  } else{
    aOut.write(4);
  }

}

MuxIF::~MuxIF() {}
