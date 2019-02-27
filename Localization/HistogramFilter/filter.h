#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <opencv2/opencv.hpp>

using std::vector;

class Histogram
{
public:
    Histogram() {}
    Histogram(int m, int n, float pSensor, float pMove) : m(m), n(n), pSensor(pSensor), pMove(pMove) {}
    void initBelief(cv::Mat&);
    void sense(bool Z, const vector<vector<bool> >&, cv::Mat&);
    void move(const vector<int>&, cv::Mat&);

private:
    int m, n;
    float pSensor, pMove;
};

#endif