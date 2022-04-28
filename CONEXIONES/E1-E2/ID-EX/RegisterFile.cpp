#include "RegisterFile.h"


RegisterFile::RegisterFile(sc_module_name nm) : sc_module(nm){
    SC_THREAD(operation); 
    sensitive << clkIn << rwIn <<raIn << rbIn;
    dont_initialize();   
     
}

void RegisterFile::operation(){           
            
        
  //  aOut = storage[raIn.read()];
//    bOut = storage[rbIn.read()];



cout<<"a"<<"raIn: "<<raIn.read()<<" rbIn: "<<rbIn.read()<<" rwIn: "<<rwIn.read()<<" "<<endl;
wait();
cout<<"raIn: "<<raIn.read()<<" rbIn: "<<rbIn.read()<<" rwIn: "<<rwIn.read()<<" "<<endl;
sc_stop();



    //cout<<"aOut: "<<aOut<<endl;
    //cout<<"bOut: "<<bOut<<endl;

    //cout<<"!!!";
    // if (weIn.read())
    // {
    //    storage[rwIn.read()] = wIn.read();
    // }       
    
    
}






