#include<iostream>
#include<systemc.h>

#include "IF-ID/ProgramCounter.h"
#include "IF-ID/Adder.h"
#include "IF-ID/MuxIF.h"
#include "IF-ID/InstructionMemory.h"
#include "IF-ID/TestbenchIF.h"

#include "ID-EX/RegisterFile.h"
#include "ID-EX/SignalExpand.h"

#include "ALU/alu.h"
#include "ALU/MuxEX.h"

#include "UC/unidad_control.h"

#include "MEM-WB/DataMemory.h"
#include "MEM-WB/Mux.h"
#include "MEM-WB/AndGate.h"


int sc_main (int argv, char* argc[]) 
{   
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    InstructionMemory IM("IM");
    ProgramCounter PC("PC");
    Adder ADD("ADD");
    MuxIF MuxIF("MuxIF");
    MuxEX MuxEx("MuxEx");
    RegisterFile RF("RF");
    TestbenchIF tb("tb");
    SignalExpand se("se");
    Alu ALU("ALU");
    UnidadControl UC("UC");
    DataMemory DM("DM");
    Mux MUXWB("MUXWB");
    AndGate ANDGATE("ANDGATE");


    sc_signal< sc_int<32> > MuxIFSg, PcSg, AddSg, RF1, ALUSg;

    sc_signal< sc_int<32> > pSignalSg, bSg, muxExSg;

    sc_signal< sc_uint<5> > rdSg, rs1Sg, rs2Sg, opcodeSg, opcode2Sg;
    sc_signal< sc_int<12> > immSg;

    sc_signal< bool > UC1, UC2, UC3, UC4, UC5, UC6, ANDSg, zeroSg;

    sc_signal< sc_int<32> > dataMSg;
    sc_signal< sc_int<32> > dataRegSg;
    sc_signal< sc_int<32> > wSg; 

    MuxIF.aIn(pSignalSg);
    MuxIF.sIn(ANDSg);
    MuxIF.aOut(MuxIFSg);

    ADD.aIn(MuxIFSg);
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

    RF.rd(rdSg);
    RF.rs1(rs1Sg);
    RF.rs2(rs2Sg);
    RF.weIn(UC1);
    RF.wIn(wSg);
    RF.aOut(RF1);
    RF.bOut(bSg);
    RF.clkIn(clock);
 
    se.immIn(immSg);
    se.immOut(pSignalSg);    

    //Conexion Multiplexor EX decide entre imm y rs2
    MuxEx.aIn(pSignalSg);
    MuxEx.bIn(bSg);
    MuxEx.s0In(UC4);
    MuxEx.cOut(muxExSg);

    ALU.aIn(RF1);
    ALU.bIn(muxExSg);
    ALU.ALUOpIn(opcode2Sg);
    ALU.aluResultOut(ALUSg);
    ALU.zeroSg(zeroSg);

    UC.opcodeIn(opcodeSg);
    UC.ALUOpOut(opcode2Sg);
    UC.RegWriteOut(UC1);
    UC.MemWriteOut(UC2);
    UC.MemReadOut(UC3);
    UC.ALUSrcOut(UC4);
    UC.branchOut(UC5);
    UC.MemtoRegOut(UC6);

    DM.dirIn(ALUSg);
    DM.wIn(bSg);
    DM.weIn(UC2);
    DM.reIn(UC3);
    DM.dataOut(dataMSg);
    DM.clkIn(clock);

    MUXWB.aIn(dataMSg);
    MUXWB.bIn(ALUSg); 
    MUXWB.cOut(wSg);
    MUXWB.s0In(UC6);

    ANDGATE.aIn(UC5);
    ANDGATE.bIn(zeroSg);
    ANDGATE.dOut(ANDSg);

    tb.pc(PcSg);
    tb.rs1(RF1);
    tb.rs2(bSg);
    tb.imm(muxExSg);
    tb.opcode(opcodeSg);
    tb.result(ALUSg);
    tb.clkIn(clock);

    sc_start();


    return 0;
}