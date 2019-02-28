#include <iostream>
#include "simulator.h"

const int nrows = 500;
const int ncols = 500;
const float pSensor = 0.8;
const float pMove = 0.8;

int main(int argc, char** argv)
{
    Simulator sim(nrows, ncols, pSensor, pMove);
    return sim.run();
}