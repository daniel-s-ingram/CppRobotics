#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
    std::string window_name = "Lane Detector";
    cv::VideoCapture video("../lane.mp4");
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    cv::Mat frame, gray, edges;
    std::vector<std::vector<cv::Point> > contours;

    int height = video.get(CV_CAP_PROP_FRAME_HEIGHT);
    int width = video.get(CV_CAP_PROP_FRAME_WIDTH);
    cv::Mat mask(height, width, CV_8UC1, cv::Scalar(0));
    std::vector<std::vector<cv::Point> > triangle;
    triangle.push_back(std::vector<cv::Point>());
    triangle[0].push_back(cv::Point(0, height));
    triangle[0].push_back(cv::Point(width, height));
    triangle[0].push_back(cv::Point(width / 2, 3 * height / 4));
    cv::drawContours(mask, triangle, 0, cv::Scalar(255), CV_FILLED, 8);

    while (true)
    {
        video >> frame;
        if (frame.empty())
            break;

        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::Canny(gray, edges, 100, 150);
        cv::bitwise_and(edges, mask, edges);
        cv::findContours(edges, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
        cv::drawContours(frame, contours, -1, cv::Scalar(0, 0, 255), 5);

        cv::imshow(window_name, frame);
        if (cv::waitKey(10) == 27)
            break;
    }
    video.release();
    cv::destroyAllWindows();
    return 0;
}