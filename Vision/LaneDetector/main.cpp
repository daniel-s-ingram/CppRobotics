#include <iostream>
#include <string>

#include "lane_detector.h"

int main(int argc, char** argv)
{
    std::string window_name = "Lane Detector";
    cv::VideoCapture video("../videos/lane.mp4");
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    int height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    int width = video.get(CV_CAP_PROP_FRAME_WIDTH);
    LaneDetector lane_detector(height, width);
    cv::Mat frame;
    while (true)
    {
        video >> frame;
        if (frame.empty())
        {
            video.set(CV_CAP_PROP_POS_FRAMES, 0);
            continue;
        }
        double begin = static_cast<double>(cv::getTickCount());
        lane_detector.detect(frame);
        double end = static_cast<double>(cv::getTickCount());
        double fps = cv::getTickFrequency() / (end - begin);
        std::cout << fps << std::endl;
        cv::imshow("Lane Detector", frame);
        if (cv::waitKey(10) == 27)
            break;
    }
    video.release();
    cv::destroyAllWindows();
    return 0;
}