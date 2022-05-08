#include <iostream>

#include "Testbench.h"

using std::cout;
using std::endl;

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
}

Testbench::~Testbench() {}

void Testbench::print() {
  cout << aOut.read() << " ";
  cout << bOut.read() << " ";
  cout << cIn.read() << endl;
}

void Testbench::test() {
  cout << "Compuerta AND" << endl;
  cout << "a b c" << endl;

  //Se comienzan a enviar los estimulos
  for (int i = 0; i <= 1; ++i) {
    for (int j = 0; j <= 1; ++j) {
      aOut.write(i);
      bOut.write(j);
      wait();
      print();
    }
  }
  sc_stop();

  /**
   * write: les mandamos valores 0 o 1 a los puertos de salida del testbench
   * (los cuales son los puertos de entrada del módulo a probar)
   *
   * wait: al ejecutar wait, el testbench espera hasta que suceda el evento clk.pos()
   * profe, pero por qué clk.pos()?
   * pues porque es lo que definimos con "sensitive<<clk.pos()" y es lo que queremos que suceda
   *
   * print: llama a print() para imprimir los resultados obtenidos antes de enviarle nuevos estimulos y proseguir con la evaluacion del modulo
   * 
   * sc_stop: para el testbench
   **/
}