#ifndef ROBOT_H
#define ROBOT_H

#include <random>
#include <cstdlib>
#include <vector>
#include <tuple>

using std::vector;

class Robot
{
public:
    int x, y;
    Robot() {}
    Robot(int m, int n, int x, int y, float pSensor, float pMove) : m(m), n(n), x(x), y(y), pSensor(pSensor), pMove(pMove) {}
    vector<int> move();
    bool sense(const vector<vector<bool> >&);

private:
    int m, n;
    float pSensor, pMove;
};

#endif