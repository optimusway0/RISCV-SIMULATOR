#include<systemc.h>
#include "InstructionMemory.h"
#include "Testbench.h"

int sc_main (int argv, char* argc[]) 
{   
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    InstructionMemory IM("IM");
    Testbench tb("tb");

    sc_signal< sc_uint<32> > pcSg;
    sc_signal< sc_uint<5> > rdSg, rs1Sg, rs2Sg, opcodeSg;
    sc_signal< sc_int<12> > immSg;

    IM.counterIn(pcSg);
    IM.rd(rdSg);
    IM.rs1(rs1Sg);
    IM.rs2(rs2Sg);
    IM.imm(immSg);
    IM.opcode(opcodeSg);

    tb.counterIn(pcSg);
    tb.rd(rdSg);
    tb.rs1(rs1Sg);
    tb.rs2(rs2Sg);
    tb.imm(immSg);
    tb.opcode(opcodeSg);
    tb.clkIn(clock);

    sc_start();

    return 0;
}