#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <algorithm>
#include <random>
#include <cstdlib>
#include <vector>
#include <opencv2/opencv.hpp>

#include "filter.h"
#include "robot.h"

using std::vector;

class Simulator
{
    public:
        Simulator(int, int, int, int, float, float, float);
        int run();

    private:
        int w, h, nLandmarks, nParticles;
        float fNoise, tNoise, sNoise;
        Robot robot;
        ParticleFilter filter;
        vector<cv::Point> landmarks;
        vector<Robot> particles;

        void initLandmarks();
        void initParticles();
        void drawScene(cv::Mat&);
        void resample(const vector<float>&);
};

#endif