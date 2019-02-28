#include "simulator.h"

const int height = 1000;
const int width = 1000;
const int nParticles = 10000;
const int nLandmarks = 25;

int main(int argc, char** argv)
{
    Simulator sim(width, height, nLandmarks, nParticles);
    return sim.run();
}