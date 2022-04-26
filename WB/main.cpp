#include "Mux.h"
#include "Testbench.h"
#include <systemc.h>

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  Mux mux("mux");
  Testbench tb("tb");

  /* A la hora de hacer signals para las datos de varios bits, se hacen de una manera 
  bastante  intuitiva.*/
  sc_signal<bool> s0Sg; //Aquí se mantiene como bool porque seguimos necesitando que sea 1 solo bit
  sc_signal< sc_int<32> > aSg, bSg, cSg;

  mux.s0In(s0Sg);
  mux.aIn(aSg);
  mux.bIn(bSg);
  mux.cOut(cSg);

  tb.cIn(cSg);
  tb.s0Out(s0Sg);
  tb.aOut(aSg);
  tb.bOut(bSg);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
