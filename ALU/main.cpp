#include "Testbench.h"
#include "alu.h"
#include "Mux.h"

int sc_main(int argv, char* argc[]) {
  
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);
  sc_clock clk("clock", period, 0.5, delay, true);

  Alu alu("aLu");
  Mux muxAluSrc("muxAluSrc");
  Testbench test("test");
 
  sc_signal<sc_int<32>> aTestSg, bTestSg;
  sc_signal<sc_int<32>> aSg, bSg;   // datos de entrada para la ALU
  sc_signal<sc_int<32>> pSignalSg;  // valor inmediato
  sc_signal<sc_int<32>> aluResultSg;
  sc_signal<bool> ALUSrcSg;
  sc_signal<sc_uint<5>> ALUOpSg;

  test.aOut(aTestSg);
  test.bOut(bTestSg);
  test.pSignalOut(pSignalSg);
  test.aluResultIn(aluResultSg);
  test.ALUOpOut(ALUOpSg);
  test.ALUSrcOut(ALUSrcSg);

  muxAluSrc.aIn(pSignalSg);
  muxAluSrc.bIn(aTestSg);
  muxAluSrc.cOut(aSg);
  muxAluSrc.s0In(ALUSrcSg);

  alu.ALUOpIn(ALUOpSg); 
  alu.aIn(aSg);
  alu.bIn(bSg);
  alu.aluResultOut(aluResultSg);

  test.clkIn(clk);

  sc_start();

  return 0;

}