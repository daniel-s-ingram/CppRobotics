#ifndef ROBOT_H
#define ROBOT_H

#include <random>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp>

using std::vector;

class Robot
{
public:
    float x, y;
    Robot() {}
    Robot(float x, float y) : x(x), y(y) {}
    vector<float> move();
    void sense(const vector<cv::Point>&, vector<float>&);
};

#endif