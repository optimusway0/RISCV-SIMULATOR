#include "Testbench.h"
#include <iomanip>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void Testbench::print(bool all) {
  std::cout << std::setw(6) << sc_time_stamp();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << ((all) ? aOut.read().to_string() : "");
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << ((all) ? bOut.read().to_string() : "");
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << s0Out.read();
  std::cout << std::setw(4) << "";
  std::cout << std::setw(4) << cIn.read();
  std::cout << "\n";
}

void Testbench::test() {
  std::cout << "Tiempo       a       b      s0       c\n";
  std::cout << "--------------------------------------\n";

  int a[] = {-4, 1, -3, 0};
  int b[] = {88, -114, 57, 119};

  for (int j=0; j<4; ++j) {
    aOut.write(a[j]);
    bOut.write(b[j]);
    for (int i=0; i<2; ++i) {
      s0Out.write(i);
      wait();
      print(i==0);
    }
    std::cout << "--------------------------------------\n";
  }
  sc_stop();
}
