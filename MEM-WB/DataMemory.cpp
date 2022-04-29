#include "DataMemory.h"

DataMemory::DataMemory(sc_module_name mn) : sc_module(mn)
{
    SC_METHOD(Read);
    sensitive << clkIn<< dirIn << wIn << dataOut;

    SC_METHOD(Write);
    sensitive << clkIn.pos() << dirIn << wIn << dataOut;
}

DataMemory::~DataMemory() {}

void DataMemory::Read() //Instruccion lw
{
    if(reIn.read() )
    {
       if(dirIn.read() % 4 == 0) 
       {
            int tope = dirIn.read();
            
            sc_int<32> valor;
 
            for(int i = tope, k = 0; i<(tope + 4); i++) 
            {
                for(int j = 0; j<8; j++) 
                {
                    valor[k] = storage[i][j];
                    k++;
                }
            }
            
            dataOut.write(valor);
       } 
    }

}

void DataMemory::Write() //Instruccion sw
{
    if(weIn.read() )
    {
        if(dirIn.read() % 4 == 0) 
        {
            int tope = dirIn.read();
            for(int i = tope, k = 0; i<(tope + 4) ; i++) 
            {
                for(int j = 0; j<8; j++) 
                {
                    storage[i][j] = wIn.read()[k];
                    k++;   
                }   
            }    
        } 
    }
}