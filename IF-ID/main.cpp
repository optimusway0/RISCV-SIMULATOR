#include<systemc.h>
#include "ProgramCounter.h"
#include "Adder.h"
#include "InstructionMemory.h"
#include "Testbench.h"

int sc_main (int argv, char* argc[]) 
{   
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    InstructionMemory IM("IM");
    ProgramCounter PC("PC");
    Adder ADD("ADD");

    Testbench tb("tb");

    sc_signal< sc_uint<32> > aSg, addSg, pcSg, tbIn;
    sc_signal< sc_uint<5> > rdSg, rs1Sg, rs2Sg, opcodeSg;
    sc_signal< sc_int<12> > immSg;

    ADD.aIn(tbIn);
    ADD.aOut(addSg);

    PC.aIn(addSg);
    PC.aOut(pcSg);

    IM.counterIn(pcSg);
    IM.rd(rdSg);
    IM.rs1(rs1Sg);
    IM.rs2(rs2Sg);
    IM.imm(immSg);
    IM.opcode(opcodeSg);

    tb.pc(tbIn);

    tb.rd(rdSg);
    tb.rs1(rs1Sg);
    tb.rs2(rs2Sg);
    tb.imm(immSg);
    tb.opcode(opcodeSg);
    tb.clkIn(clock);

    sc_start();

    return 0;
}