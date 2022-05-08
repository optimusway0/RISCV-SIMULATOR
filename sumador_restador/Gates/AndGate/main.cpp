#include "Testbench.h"
#include "AndGate.h"
#include "AndGate_3.h"
#include "Testbench2.h"

int sc_main(int argc, char* argv[]) {
  sc_time PERIOD(10, SC_NS); //SC_PS SC_SEC . . .
  sc_time DELAY(10, SC_NS);
  sc_clock clock("clock", PERIOD, 0.5, DELAY, true); // creamos el reloj

  /*
  // Creamos los módulos
  AndGate ag1("ag1");
  Testbench tb("tb");

  // Creamos los cables (o "signals" en otro sentido de abstracción)
  sc_signal<bool> aSg, bSg, cSg; //los cables que unen los puertos (ejm: la salida c del módulo AndGate con la entrada c del testbench)

  // Conectamos los cables
  ag1.aIn(aSg); // conectando la entrada a del módulo AndGate con el cable aSg
  ag1.bIn(bSg); // conectando la entrada b del módulo AndGate con el cable bSg
  ag1.cOut(cSg); // conectando la salida c del módulo AndGate con el cable cSg

  tb.aOut(aSg); // conectando la salida a del testbench con el cable aSg
  tb.bOut(bSg); // conectando la salida b del testbench con el cable bSg
  tb.cIn(cSg); // conectando la entrada c del testbench con el cable cSg

  tb.clkIn(clock); // conectando la entrada clkIn del testbench con (no un cable, sino con el reloj directamente)

  */
  //Prueba de compuerta and de 3 entradas
  AndGate_3 and_3("and_3");
  Testbench2 tb2("tb2");

  sc_signal<bool> a2Sg, b2Sg, c2Sg, d2Sg;

  and_3.aIn(a2Sg);
  and_3.bIn(b2Sg);
  and_3.cIn(c2Sg);
  and_3.dOut(d2Sg);

  tb2.aOut(a2Sg);
  tb2.bOut(b2Sg);
  tb2.cOut(c2Sg);
  tb2.dIn(d2Sg);
  tb2.clkIn(clock);

  sc_start();
  return 0;
}
