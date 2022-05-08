#include "FullAdder.h"

FullAdder::FullAdder(sc_module_name mn) : sc_module(mn)
{
    and1 = new AndGate("and1");
    and2 = new AndGate("and2");
    orGate = new OrGate("orGate");
    xor1 = new XorGate("xor1");
    xor2 = new XorGate("xor2");

    //conexiones internas
    and1->aIn(bIn);
    and1->bIn(aIn);
    and1->cOut(sg1);

    and2->aIn(sg0);
    and2->bIn(carryIn);
    and2->cOut(sg2);

    orGate->aIn(sg2);
    orGate->bIn(sg1);
    orGate->cOut(carryOut);

    xor1->aIn(aIn);
    xor1->bIn(bIn);
    xor1->cOut(sg0);

    xor2->aIn(carryIn);
    xor2->bIn(sg0);
    xor2->cOut(resultOut);
}

FullAdder::~FullAdder()
{
    delete and1;
    delete and2;
    delete orGate;
    delete xor1;
    delete xor2;
}
