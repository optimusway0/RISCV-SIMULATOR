#include "Testbench.h"
#include "alu.h"
#include "unidad_control.h"

int sc_main(int argv, char* argc[]) {
  
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);
  sc_clock clk("clock", period, 0.5, delay, true);

  Alu alu("aLu");
  UnidadControl uc("unidad_control");
  Testbench test("test");

  sc_signal<bool> werSg;
  sc_signal<sc_uint<5>> opcodeSg; 
  sc_signal<sc_int<32>> aSg, bSg;
  sc_signal<sc_int<32>> aluResultSg;
  sc_signal<sc_uint<5>> aluOpSg;

  test.opcodeOut(opcodeSg);
  uc.opcodeIn(opcodeSg);
  test.werIn(werSg);
  uc.werOut(werSg);

  test.aOut(aSg);
  alu.aIn(aSg);
  test.bOut(bSg);
  alu.bIn(bSg);
  test.aluResultIn(aluResultSg);
  alu.aluResultOut(aluResultSg);

  alu.aluOpIn(aluOpSg);
  uc.aluOpOut(aluOpSg);

  test.clkIn(clk);

  sc_start();

  return 0;

}