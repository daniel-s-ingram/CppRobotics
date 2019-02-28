#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <random>
#include <cstdlib>
#include <vector>
#include <opencv2/opencv.hpp>

using std::vector;

class Simulator
{
public:
    Simulator(int, int, int, int);
    void initLandmarks();
    int run();

private:
    int w, h, nLandmarks, nParticles;
    vector<cv::Point> landmarks;
};

#endif