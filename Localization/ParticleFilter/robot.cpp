#include "robot.h"

Robot Robot::move(float turn, float forward)
{

}

void Robot::sense(const vector<cv::Point>& landmarks, vector<float>& Z)
{
    
}

std::ostream& operator<<(std::ostream& os, const Robot& robot)
{
    return os << robot.pos << " " << robot.yaw;
}

std::ostream& operator<<(std::ostream& os, const vector<Robot>& robots)
{
    for (auto& robot : robots)
    {
        os << robot << std::endl;
    }
    return os;
}
