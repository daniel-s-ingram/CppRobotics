#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <opencv2/opencv.hpp>

#include "robot.h"
#include "filter.h"

using std::vector;

class Simulator
{
public:
    Simulator(int, int, float, float);
    void initMap(vector<vector<bool> >& map);
    int run();

private:
    int m, n;
    float pSensor, pMove;
    vector<vector<bool> > map;
    cv::Mat pMap;
    Histogram filter;
    Robot robot;
};

#endif