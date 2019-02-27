#include "common.h"
#include "robot.h"

vector<int> Robot::move()
{
    int dx = std::rand() % 3 - 1;
    int dy = std::rand() % 3 - 1;
    vector<int> d{dx, dy};
    x = mod((x + dx), n);
    y = mod((y + dy), m);
    return d;
}

bool Robot::sense(const vector<vector<bool> >& map)
{
    bool Z = map[y][x];
    float r = (float)std::rand() / RAND_MAX;
    if (r < pSensor)
        return Z;
    else
        return !Z;
}