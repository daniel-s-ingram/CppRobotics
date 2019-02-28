#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <opencv2/opencv.hpp>

#include "common.h"
#include "filter.h"

using std::vector;

void Histogram::initBelief(cv::Mat& P)
{
    float* ptr;
    for (int i = 0; i < P.rows; i++)
    {
        ptr = P.ptr<float>(i);
        for (int j = 0; j < P.cols; j++)
        {
            ptr[j] = 1.0/((double)m*n);
        }
    }
}

void Histogram::sense(bool Z, const vector<vector<bool> >& map, cv::Mat& P)
{
    int hit;
    float norm = 0;
    float* ptr;
    
    //TODO: Parallel for loop
    for (int i = 0; i < P.rows; i++)
    {
        ptr = P.ptr<float>(i);
        for (int j = 0; j < P.cols; j++)
        {
            hit = map[i][j] == Z;
            ptr[j] *= (hit * pSensor + (1 - hit) * (1 - pSensor));
            norm += ptr[j];
        }
    }

    for (int i = 0; i < P.rows; i++)
    {
        ptr = P.ptr<float>(i);
        for (int j = 0; j < P.cols; j++)
        {
            ptr[j] /= norm;
        }
    }
}

void Histogram::move(const vector<int>& d, cv::Mat& P)
{
    cv::Mat auxP = P.clone();
    for (int i = 0; i < P.rows; i++)
    {
        for (int j = 0; j < P.cols; j++)
        {
            //TODO: Do this a better way
            P.at<float>(i, j) = pMove*auxP.at<float>(mod(i-d[0], m), mod(j-d[1], n)) + (1.0 - pMove)*auxP.at<float>(i, j);
        }
    }  
}