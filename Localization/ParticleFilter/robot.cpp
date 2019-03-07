#include "robot.h"

Robot::Robot(cv::Point pos, float yaw, float fNoise, float tNoise, float sNoise) : pos(pos), yaw(yaw), fNoise(fNoise), tNoise(tNoise), sNoise(sNoise)
{
    unsigned seed = std::random_device()();
    gen.seed(seed);
}

Robot Robot::move(float turn, float forward)
{
    std::normal_distribution<float> tGauss(turn, tNoise);
    std::normal_distribution<float> fGauss(forward, fNoise);

    yaw += tGauss(gen);
    yaw = std::fmod(yaw, 2 * M_PI);

    float d = fGauss(gen);
    pos.x += d * std::cos(yaw);
    pos.y += d * std::sin(yaw);

    Robot p = Robot(pos, yaw, fNoise, tNoise, sNoise);
    return p;
}

void Robot::sense(const vector<cv::Point>& landmarks, vector<float>& Z)
{
    Z.clear();
    std::normal_distribution<float> sGauss(0, sNoise);
    for (auto& lm : landmarks)
    {
        float d = std::sqrt(std::pow((pos.x - lm.x), 2) + std::pow((pos.y - lm.y), 2));
        d += sGauss(gen);
        Z.push_back(d);
    }
}

void Robot::setPose(float x, float y, float yaw)
{
    x = x; y = y; yaw = yaw;
}

void Robot::setNoise(float fNoise, float tNoise, float sNoise)
{
    fNoise = fNoise; tNoise = tNoise; sNoise = sNoise;
}

float Robot::measProb(const vector<cv::Point>& lm, const vector<float>& Z)
{
    float P = 1.0;
    for (auto i = 0; i < lm.size(); i++)
    {
        float d = std::sqrt(std::pow((pos.x - lm[i].x), 2) + std::pow((pos.y - lm[i].y), 2));
        P *= Gaussian(d, sNoise, Z[i]);
    }
    return P;
}

float Robot::Gaussian(float mean, float var, float x)
{
    float val = std::exp(-std::pow((mean - x), 2.0) / (2 * std::pow(var, 2.0)));
    return val / std::sqrt(2 * M_PI * std::pow(var, 2));
}

std::ostream& operator<<(std::ostream& os, const Robot& robot)
{
    return os << robot.pos;
}

std::ostream& operator<<(std::ostream& os, const vector<Robot>& robots)
{
    for (auto& robot : robots)
    {
        os << robot << std::endl;
    }
    return os;
}
