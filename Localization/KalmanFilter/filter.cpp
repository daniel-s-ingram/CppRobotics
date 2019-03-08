#include "filter.h"

Kalman::Kalman(float initX, float initY, float dt, const vector<float>& stateVar, const vector<float>& measVar)
{
    //Identity matrix
    I << 1, 0, 0, 0,
         0, 1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1;

    //State transition matrix
    F << 1, 0, dt,  0,
         0, 1,  0, dt,
         0, 0,  1,  0,
         0, 0,  0,  1;

    //Measurement function
    H << 1, 0, 0, 0,
         0, 1, 0, 0;

    //Measurement covariance
    R << measVar[0],          0,
                  0, measVar[1];

    //State covariance
    P << stateVar[0],           0,           0,           0,
                   0, stateVar[1],           0,           0,
                   0,           0, stateVar[2],           0,
                   0,           0,           0, stateVar[3];
}

void Kalman::predict(const Eigen::Vector4f& u, Eigen::Vector4f& x)
{
    x = F * x + u;
    P = F * P * F.transpose();
}

void Kalman::update(const Eigen::RowVector2f& Z, Eigen::Vector4f& x)
{
    y = Z.transpose() - H * x;
    S = H * P * H.transpose() + R;
    K = P * H.transpose() * S.inverse();
    x = x + K * y;
    P = (I - K * H) * P;
}