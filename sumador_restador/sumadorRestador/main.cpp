#include <systemc.h>
#include "AddSub.h"
#include "Testbench.h"

int sc_main(int argc, char *argv[])
{
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, true);

    AddSub sumadorRestador("sumadorRestador");
    Testbench tb("tb");

    sc_signal< sc_int<ADD_SUB_BITS> > RSg, ASg, BSg;
    sc_signal<bool> cSg, ovSg, controlSg;

    sumadorRestador.aIn(ASg);
    sumadorRestador.bIn(BSg);
    sumadorRestador.rOut(RSg);

    tb.aOut(ASg);
    tb.bOut(BSg);
    tb.rIn(RSg);
    
    sumadorRestador.controlIn(controlSg);
    sumadorRestador.carryOut(cSg);
    sumadorRestador.overflowOut(ovSg);

    tb.carryIn(cSg);
    tb.overflowIn(ovSg);
    tb.controlOut(controlSg);
    tb.clkIn(clock);

    sc_start();

    return 0;
}