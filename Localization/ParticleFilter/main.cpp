#include "simulator.h"

const int height = 1000;
const int width = 1000;
const int nParticles = 1000;
const int nLandmarks = 10;
const float forward_noise = 0.05;
const float turn_noise = 0.05;
const float sensor_noise = 5;

int main(int argc, char** argv)
{
    Simulator sim(width, height, nLandmarks, nParticles, forward_noise, turn_noise, sensor_noise);
    return sim.run();
}