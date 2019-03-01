#include "simulator.h"

Simulator::Simulator(int w, int h, int nL, int nP) : w(w), h(h), nLandmarks(nL), nParticles(nP)
{
    initLandmarks();
    initParticles();
    robot = Robot(cv::Point(w/2, h/2), 0);
    std::cout << particles << std::endl;
}

void Simulator::initLandmarks()
{
    srand(time(NULL));
    for (int i = 0; i < nLandmarks; i++)
    {
        float x = w * (double)std::rand() / RAND_MAX;
        float y = h * (double)std::rand() / RAND_MAX;
        landmarks.push_back(cv::Point(x, y));
    }
}

void Simulator::initParticles()
{
    for (int i = 0; i < nParticles; i++)
    {
        float x = w * (double)std::rand() / RAND_MAX;
        float y = h * (double)std::rand() / RAND_MAX;
        float yaw = 2 * M_PI * (double)std::rand() / RAND_MAX;
        particles.push_back(Robot(cv::Point(x, y), yaw)); 
    }
}

int Simulator::run()
{
    return 0; 
}