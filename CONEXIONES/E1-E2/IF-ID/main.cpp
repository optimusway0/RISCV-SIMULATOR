#include <systemc.h>
#include "ProgramCounter.h"
#include "Adder.h"
#include "InstructionMemory.h"
#include "../ID-EX/RegisterFile.h"
#include "../ID-EX/SignalExpand.h"
#include "../ID-EX/PrintSignal.h"
#include "TestPrint.h"

int sc_main (int argv, char* argc[]) 
{   
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    InstructionMemory IM("IM");
    ProgramCounter PC("PC");
    Adder ADD("ADD");
    RegisterFile RF("RF");
    SignalExpand SE ("SE"); //Expansion del entero. 
    TestPrint TP("TP");
    PrintSignal PS("PS");

    sc_signal< sc_uint<32> > aSg, addSg, pcSg, tbIn;
    sc_signal< sc_uint<5> > rdSg, rs1Sg, rs2Sg, opcodeSg;
    sc_signal< sc_int<12> > immSg; 
    sc_signal<sc_int<32>> pSignalSg;   

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
    TP.opcodeIn(opcodeSg);

    RF.rwIn(rdSg);
    RF.raIn(rs1Sg);
    RF.rbIn(rs2Sg);
    SE.immIn(immSg);   

    SE.immOut(pSignalSg);
    PS.immIn(pSignalSg); 
    RF.clkIn(clock);
    
    


    
    //tb.clkIn(clock);

    sc_start();

    return 0;
}