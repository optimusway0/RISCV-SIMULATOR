#include "Testbench.h"
#include "unidad_control.h"

int sc_main(int argv, char* argc[]) {
  
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);
  sc_clock clk("clock", period, 0.5, delay, true);

  UnidadControl uc("unidad_control");
  Testbench test("test");

  sc_signal<sc_uint<5>> opcodeSg;
  sc_signal<sc_uint<5>> ALUOpSg;
  sc_signal<bool> ALUSrcSg, MemtoRegSg, RegWriteSg, MemWriteSg, MemReadSg, branchSg;

  uc.opcodeIn(opcodeSg);
  uc.ALUOpOut(ALUOpSg);
  uc.ALUSrcOut(ALUSrcSg);
  uc.MemtoRegOut(MemtoRegSg);
  uc.RegWriteOut(RegWriteSg);
  uc.MemWriteOut(MemWriteSg);
  uc.MemReadOut(MemReadSg);
  uc.branchOut(branchSg);

  test.opcodeOut(opcodeSg);
  test.ALUOpIn(ALUOpSg); 
  test.ALUSrcIn(ALUSrcSg);
  test.MemtoRegIn(MemtoRegSg);
  test.RegWriteIn(RegWriteSg);
  test.MemWriteIn(MemWriteSg);
  test.MemReadIn(MemReadSg);
  test.branchIn(branchSg);

  test.clkIn(clk);

  sc_start();

  return 0;

}