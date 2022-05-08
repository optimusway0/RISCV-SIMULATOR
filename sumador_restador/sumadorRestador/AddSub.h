#ifndef ADD_SUB_H
#define ADD_SUB_H

#include <systemc.h>
#include "Gates/AndGate/AndGate.h"
#include "Gates/OrGate/OrGate.h"
#include "Gates/XorGate/XorGate.h"
#include "fullAdder/FullAdder.h"  
#include "Gates/NotGate/NotGate.h"
#include "Gates/AndGate/AndGate_3.h"

const int ADD_SUB_BITS = 32;
const int NUM_ANDS = 2;
const int NUM_XORS = 32;
const int NUM_FULL_ADDERS = 32; 
const int NUM_NOTS = 3;

class AddSub : public sc_module
{
private:
    
    sc_vector<FullAdder> fullAdders;
    sc_vector<AndGate_3> andGates;
    OrGate orGate; 
    sc_vector<NotGate> notGateS;
    sc_vector<XorGate> xorGateS;
    
    sc_signal<bool> xorSg[NUM_XORS];
    sc_signal<bool> carrySg[NUM_FULL_ADDERS - 1];
    sc_signal<bool> notSg[NUM_NOTS];
    sc_signal<bool> andSg[NUM_ANDS];
    sc_signal<bool> aSg[ADD_SUB_BITS];
    sc_signal<bool> bSg[ADD_SUB_BITS];
    sc_signal<bool> rSg[ADD_SUB_BITS];

    void assemble();

public:
    SC_CTOR(AddSub);
    ~AddSub();
    
    sc_in< sc_int<ADD_SUB_BITS> > aIn, bIn;
    sc_in<bool> controlIn;
    sc_out<bool> carryOut, overflowOut;
    sc_out< sc_int<ADD_SUB_BITS> > rOut;

};

#endif //ADD_SUB_H