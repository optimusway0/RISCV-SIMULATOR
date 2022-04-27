#include "RegisterFile.h"


RegisterFile::RegisterFile(sc_module_name nm) : sc_module(nm){
    SC_METHOD(operation);    
    sensitive<< weIn << rwIn <<raIn << rbIn;   
     
}

void RegisterFile::operation(){           
            
        
    aOut.write(storage[raIn.read()]);
    bOut.write(storage[rbIn.read()]);

    if (weIn.read())
    {
       storage[rwIn.read()] = wIn.read();
    }       
    
    
}






