#include "RegisterFile.h"
RegisterFile::RegisterFile(sc_module_name nm) : sc_module(nm){
    
    // for (int i = 7; i < 19; i++)
    // {
    //   storage[i] = i; //Que inicialice con esos valores en los registros donde se almacenan los datos. 
    // }
    
    SC_METHOD(operation); 
    sensitive << rs1<< rs2<<rd<<clkIn;     
}

void RegisterFile::operation(){    
    //cout << "leyendo " << rs1.read() << " y " << rs2.read() << " que son " << storage[rs1.read()] << " y " << storage[rs2.read()]<< endl;       

    aOut.write(storage[rs1.read()]);
    bOut.write(storage[rs2.read()]);

    if (weIn.read())
    {
       storage[rd.read()] = wIn.read();
       print();
    }       
}

void RegisterFile::print(){
    cout << "Registros" << endl;
    for(int i = 0; i<30; i++){
        cout << "|" << storage[i] << "|";
    }
    cout << endl << endl;
}






