#include<iostream>
#include<systemc.h>
#include "DataMemory.h"
#include "Testbench.h"
#include "Mux.h"
#include "AndGate.h"

int sc_main (int argv, char* argc[]) 
{   
    sc_time period(10,SC_NS);
    sc_time delay(10,SC_NS);

    sc_clock clock("clock", period, 0.5, delay, true);

    DataMemory DM("DM");
    Mux MUXWB("MUXWB");
    AndGate ANDGATE("ANDGATE");
    Testbench tb("tb");

    sc_signal<bool> memWriteSg, memReadSg; // estos cables conectan con Unidad de Control (memRead y memWrite)
    sc_signal< sc_int<32> > aluResultSg; // Este cable conecta el resultado de la ALU con la DataMemory y con el mux de la etapa WB
    sc_signal< sc_int<32> > dataMSg;
    sc_signal< sc_int<32> > dataRegSg; //Este cable conecta la salida bOut del regFile con la entrada wIn del DataMemory 
    sc_signal< sc_int<32> > wSg; // conectan la salida del mux de la etapa wb con la entrada wIn del archivo de registros
    sc_signal<bool> branchSg; //Cable que conecta con la unidad de control la salida branchOut y la compuerta And de la etapa MEM
    sc_signal<bool> zeroSg; //cable que conecta con la ALU y la compuerta AND de la etapa MEM
    sc_signal<bool> mentoRegSg; // cable que conecta salida mentoReg de la UC con el mux de la etapa 5 WB
    sc_signal<bool> tbSgb; // conecta con el mux de la etapa 1 IF y la salida de la compuerta AND de la etapa MEM

    DM.dirIn(aluResultSg);
    DM.wIn(dataRegSg);
    DM.dataOut(dataMSg);
    DM.weIn(memWriteSg);
    DM.reIn(memReadSg);
    DM.clkIn(clock);

    MUXWB.aIn(dataMSg);
    MUXWB.bIn(aluResultSg); 
    MUXWB.cOut(wSg);
    MUXWB.s0In(mentoRegSg);

    ANDGATE.aIn(branchSg);
    ANDGATE.bIn(zeroSg);
    ANDGATE.dOut(tbSgb);

    tb.dirOut(aluResultSg);
    tb.wOut(dataRegSg);
    tb.wIn(wSg);
    tb.weOut(memWriteSg);
    tb.reOut(memReadSg);
    tb.branchOut(branchSg);
    tb.zeroOut(zeroSg);
    tb.mentoReg(mentoRegSg);
    tb.muxIfIn(tbSgb);
    tb.clkIn(clock);
    
    sc_start();

    return 0;
}