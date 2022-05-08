#include <systemc.h>
#include "FullAdder.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[])
{
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    // Creando el reloj
    sc_clock clock("clock", period, 0.5, delay, true);

    FullAdder fullAdder("fullAdder");
    Testbench tb("tb");

    sc_signal<bool> carryISg, rSg, carryOSg, aSg, bSg;

    fullAdder.aIn(aSg);
    fullAdder.bIn(bSg);
    fullAdder.carryIn(carryISg);
    fullAdder.resultOut(rSg);
    fullAdder.carryOut(carryOSg);

    tb.aOut(aSg);
    tb.bOut(bSg);
    tb.carryIn(carryOSg);
    tb.carryOut(carryISg);
    tb.rIn(rSg);
    tb.clkIn(clock);

    sc_start();

    return 0;
}