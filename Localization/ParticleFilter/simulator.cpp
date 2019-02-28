#include "simulator.h"

Simulator::Simulator(int w, int h, int nL, int nP) : w(w), h(h), nLandmarks(nL), nParticles(nP)
{
    initLandmarks();
}

void Simulator::initLandmarks()
{
    srand(time(NULL));
    for (int i = 0; i < nLandmarks; i++)
    {
        int x = std::rand() % w;
        int y = std::rand() % h;
        landmarks.push_back(cv::Point(x, y));
    }
}

int Simulator::run()
{
    return 0; 
}