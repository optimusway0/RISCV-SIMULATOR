#include "Testbench.h"
#include "alu.h"

int sc_main(int argv, char* argc[]) {
  
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);
  sc_clock clk("clock", period, 0.5, delay, true);

  Alu alu("aLu");
  Testbench test("test");
 
  sc_signal<sc_int<32>> aSg, bSg;
  sc_signal<sc_int<32>> aluResultSg;
  sc_signal<sc_uint<5>> ALUOpSg;

  test.ALUOpOut(ALUOpSg);
  test.aOut(aSg);
  test.bOut(bSg);
  test.aluResultIn(aluResultSg);

  alu.ALUOpIn(ALUOpSg); 
  alu.aIn(aSg);
  alu.bIn(bSg);
  alu.aluResultOut(aluResultSg);

  test.clkIn(clk);

  sc_start();

  return 0;

}