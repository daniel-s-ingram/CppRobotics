#include "simulator.h"

Simulator::Simulator(int m, int n, float pSensor, float pMove) : m(m), n(n), pSensor(pSensor), pMove(pMove)
{
    cv::namedWindow("Histogram Filter", 0);

    map = vector<vector<bool> >(m, vector<bool>(n, false));
    initMap(map);

    pMap = cv::Mat(m, n, CV_32F);
    filter = Histogram(m, n, pSensor, pMove);
    filter.initBelief(pMap);

    robot = Robot(m, n, m/2, n/2, pSensor, pMove);
}

void Simulator::initMap(vector<vector<bool> >& map)
{
    srand(time(NULL));
    for (auto& row : map)
    {
        for (auto&& cell : row)
        {
            cell = (double)std::rand() / RAND_MAX > 0.9 ? true : false;
        }
    }
}

int Simulator::run()
{
    bool Z;
    vector<int> d(2);
    while (true)
    {
        Z = robot.sense(map);
        d = robot.move();
        filter.sense(Z, map, pMap);
        filter.move(d, pMap);
        cv::imshow("Histogram Filter", 100000*pMap);
        if (cv::waitKey(1) == 27)
            break;
    }
    return 0; 
}