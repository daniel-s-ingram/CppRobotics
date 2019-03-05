#ifndef ROBOT_H
#define ROBOT_H

#include <random>
#include <vector>
#include <cmath>
#include <chrono>
#include <opencv2/opencv.hpp>

using std::vector;

class Robot
{
    friend std::ostream& operator<<(std::ostream& os, const Robot& robot);
    friend class Simulator;

    public:
        Robot() {}
        Robot(cv::Point pos, float yaw, float fNoise, float tNoise, float sNoise);
        Robot move(float turn, float forward);
        void sense(const vector<cv::Point>&, vector<float>&);
        void setPose(float, float, float);
        void setNoise(float, float, float);
        float measProb(const vector<cv::Point>&, const vector<float>&);
        float Gaussian(float, float, float);

    private:
        float yaw, fNoise, tNoise, sNoise;
        cv::Point pos;
        std::mt19937 gen;
};

std::ostream& operator<<(std::ostream& os, const Robot& robot);
std::ostream& operator<<(std::ostream& os, const vector<Robot>& robots);

#endif