#include<iostream>
#include<systemc.h>

#include "DataMemory.h"
#include "Testbench.h"

int sc_main (int argv, char* argc[]) 
{   
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, true);

    DataMemory memory("memory");
    Testbench tb("tb");

    sc_signal<bool> weSg;
    sc_signal< sc_uint<32> > dirSg;
    sc_signal< sc_int<32> > dataSg, wSg;

    memory.dirIn(dirSg);
    memory.wIn(wSg);
    memory.dataOut(dataSg);
    memory.weIn(weSg);
    memory.clkIn(clock);

    tb.dirOut(dirSg);
    tb.wOut(wSg);
    tb.dataIn(dataSg);
    tb.weOut(weSg);
    tb.clkIn(clock);

    sc_start();

    return 0;
}