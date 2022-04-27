#include "Testbench.h"


Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clk.pos();
  dont_initialize();
}

void Testbench::print() {
      cout<<" "<<weOut.read()<<"     "<<wOut.read()<<"     "<<raOut.read()<<"         "<<rbOut.read()<<"        "<<rwOut.read()<<"        "<<aIn.read()<<"     "<<bIn.read()<<endl;

}

void Testbench::test() {

   cout<<"Tiempo     we     w     Dira     Dirb     DirW     aOut     bOut"<<endl;
   cout<<"-----------------------------------------------------------------"<<endl;

    std::cout << sc_time_stamp() << "     ";
    weOut.write(true);
    wOut.write(620);
    rwOut.write(15);
    raOut.write(1);
    rbOut.write(9);
    wait();
    print();

    std::cout << sc_time_stamp() << "     ";
    weOut.write(true);
    wOut.write(400);
    rwOut.write(10);
    raOut.write(11);
    rbOut.write(4);
    wait();
    print();   

    
        
   
  sc_stop();
  }

  

