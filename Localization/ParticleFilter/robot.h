#ifndef ROBOT_H
#define ROBOT_H

#include <random>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp>

using std::vector;

class Robot
{
    friend std::ostream& operator<<(std::ostream& os, const Robot& robot);

    public:
        Robot() {}
        Robot(cv::Point pos, float yaw) : pos(pos), yaw(yaw) {}
        Robot move(float turn, float forward);
        void sense(const vector<cv::Point>&, vector<float>&);

    private:
        cv::Point pos;
        float yaw;
};

std::ostream& operator<<(std::ostream& os, const Robot& robot);
std::ostream& operator<<(std::ostream& os, const vector<Robot>& robots);

#endif