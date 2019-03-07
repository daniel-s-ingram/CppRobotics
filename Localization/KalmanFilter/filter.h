#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <eigen3/Eigen/Core>

using std::vector;

class Kalman
{
    public:
        Kalman() {};
        Kalman(float, float, float, const vector<float>&, const vector<float>&);

    private:
        Eigen::Matrix<float, 4, 4> I, F, P;
        Eigen::Matrix<float, 2, 4> H;
        Eigen::Matrix<float, 2, 2> R;
        Eigen::Matrix<float, 4, 1> x, u;
};

#endif