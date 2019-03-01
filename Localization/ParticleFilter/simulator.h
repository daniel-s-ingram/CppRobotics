#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <random>
#include <cstdlib>
#include <vector>
#include <opencv2/opencv.hpp>

#include "robot.h"

using std::vector;

class Simulator
{
    public:
        Simulator(int, int, int, int);
        void initLandmarks();
        void initParticles();
        int run();

    private:
        int w, h, nLandmarks, nParticles;
        Robot robot;
        vector<cv::Point> landmarks;
        vector<Robot> particles;
};

#endif