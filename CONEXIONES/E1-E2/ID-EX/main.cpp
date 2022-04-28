
#include "Testbench.h"
#include "RegisterFile.h"

int sc_main(int argv, char* argc[]) {
  
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);
  sc_clock clock("clock", period, 0.5, delay, true);

  RegisterFile rf("registerFile");
  Testbench test("test");
  
  sc_signal<bool>weSg;
  sc_signal<sc_int<32>> wSg,waSg, wbSg;       //write a wa
  sc_signal<sc_int<5>> rwSg,raSg,rbSg;
  
  test.weOut(weSg);
  rf.weIn(weSg);

  rf.rwIn(rwSg);
  test.rwOut(rwSg);

  rf.raIn(raSg);
  test.raOut(raSg);

  rf.rbIn(rbSg);
  test.rbOut(rbSg);

  rf.wIn(wSg);
  test.wOut(wSg);

  rf.aOut(waSg);
  test.aIn(waSg);
  rf.bOut(wbSg);
  test.bIn(wbSg);

  //Simulacion de datos que ya estaban dentro del archivo de registro.
  rf.storage[0] = 122;
  rf.storage[1] = 311;
  rf.storage[4] = 999;
  rf.storage[11] = 111;
  rf.storage[9] = 300;

  test.clk(clock);
 
  

  sc_start();

  return 0;
}

// En el resultado de la impresion estaria mostrando lo siguiente y es el we que es el Write Enable esto es una senal 
// de control para que si efectivamente en la direccion Dir W se va a guardar el dato que viene desde w esto en lo que 
// el camino de datos se refiere es lo que nos retorna del WriteBack de la operacion realizada en la ALU o bien de algo 
// cargado desde la Memoria

// Tenemos W que como bien comente anteriormente es la entrada que se escribira o.. no en la direccion Dirw o como el diagrama muestra wIn 

// Siguiente a eso tenemos Dira analogo a Dirb que seran las direcciones donde se 
// deben consultar dentro del archivo de registro para ponerlas en salida o bien 
// en la seccion del diagrama aOut y bOut, que bien son las siguientes en la impresion

// Entonces como conclusion ingresamos la direccion de a y b de 5bits y este valor lo mostramos a la salida
// en conjunto a esto tenemos una senal de control el weIn que nos dira si lo que tenemos en wIn lo escribriremos 
// en la direccion rwln que en la impresion lo coloque como DirW.
