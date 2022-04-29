#include<systemc.h>
#include "ProgramCounter.h"
#include "Adder.h"
#include "Mux.h"
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
    Mux MUX("MUX");

    Testbench tb("tb");

    sc_signal< sc_int<32> > MuxSg, PcSg, AddSg;

    sc_signal< sc_int<32> > TbSga;
    sc_signal< bool > TbSgb;

    sc_signal< sc_uint<5> > rdSg, rs1Sg, rs2Sg, opcodeSg;
    sc_signal< sc_int<12> > immSg;

    MUX.aIn(TbSga);
    MUX.sIn(TbSgb);
    MUX.aOut(MuxSg);

    ADD.aIn(MuxSg);
    ADD.bIn(PcSg);
    ADD.aOut(AddSg);

    PC.aIn(AddSg);
    PC.clkIn(clock);
    PC.aOut(PcSg);

    IM.counterIn(PcSg);
    IM.rd(rdSg);
    IM.rs1(rs1Sg);
    IM.rs2(rs2Sg);
    IM.imm(immSg);
    IM.opcode(opcodeSg);

    tb.rd(rdSg);
    tb.rs1(rs1Sg);
    tb.rs2(rs2Sg);
    tb.imm(immSg);
    tb.opcode(opcodeSg);
    tb.clkIn(clock);

    tb.jump(TbSga);
    tb.eJump(TbSgb);

    sc_start();

    return 0;
}