#include <iostream>
#include "simulator.h"

const int M = 5;
const int N = 5;
const float sensor_right = 0.8;
const float p_move = 0.7;

int main(int argc, char** argv)
{
    Simulator sim(M, N, sensor_right, p_move);
    return sim.run();
}