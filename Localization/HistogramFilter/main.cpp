#include <iostream>
#include "simulator.h"

const int nrows = 1000;
const int ncols = 1000;
const float pSensor = 0.8;
const float pMove = 0.7;

int main(int argc, char** argv)
{
    Simulator sim(nrows, ncols, pSensor, pMove);
    return sim.run();
}