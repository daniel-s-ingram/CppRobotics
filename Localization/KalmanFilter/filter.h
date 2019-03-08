#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/LU>

using std::vector;

class Kalman
{
    public:
        Kalman() {};
        Kalman(float, float, float, const vector<float>&, const vector<float>&);
        void predict(const Eigen::Vector4f& u, Eigen::Vector4f& x);
        void update(const Eigen::RowVector2f& Z, Eigen::Vector4f& x);

    private:
        Eigen::Vector2f y;
        Eigen::Matrix4f I, F, P;
        Eigen::Matrix2f R, S;
        Eigen::Matrix<float, 2, 4> H;
        Eigen::Matrix<float, 4, 2> K;
};

#endif