#include "simulator.h"

Simulator::Simulator(int m, int n, float pSensor, float pMove) : m(m), n(n), pSensor(pSensor), pMove(pMove)
{
    cv::namedWindow("Histogram Filter", 0);

    map = vector<vector<bool> >(m, vector<bool>(n, false));
    initMap(map);

    pMap = cv::Mat(m, n, CV_32FC1);
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
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::Mat img(m, n, CV_32FC1);
    vector<int> d(2);
    while (true)
    {
        Z = robot.sense(map);
        d = robot.move();
        filter.sense(Z, map, pMap);
        filter.move(d, pMap);
        cv::minMaxLoc(pMap, &minVal, &maxVal, &minLoc, &maxLoc);
        cv::cvtColor(1-pMap/maxVal, img, cv::COLOR_GRAY2BGR);
        cv::circle(img, cv::Point(robot.y, robot.x), 1, cv::Scalar(0, 0, 255), -1);
        std::cout << "Actual robot location:    [" << robot.y << ", " << robot.x << "]\n"
                     "Estimated robot location: " << maxLoc << std::endl;
        cv::imshow("Histogram Filter", img);
        if (cv::waitKey(1) == 27)
            break;
    }
    return 0; 
}