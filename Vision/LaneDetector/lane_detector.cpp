#include "lane_detector.h"

LaneDetector::LaneDetector(int height, int width) : height(height), width(width)
{
    init_roi_mask();
    init_perspective_transform();
}

void LaneDetector::init_roi_mask()
{
    mask = cv::Mat(height, width, CV_8UC1, cv::Scalar(0));
    std::vector<std::vector<cv::Point> > triangle;
    triangle.push_back(std::vector<cv::Point>());
    triangle[0].push_back(cv::Point(0, height));
    triangle[0].push_back(cv::Point(width, height));
    triangle[0].push_back(cv::Point(width / 2, height / 2));
    cv::drawContours(mask, triangle, 0, cv::Scalar(255), CV_FILLED, 8);   
}

void LaneDetector::init_perspective_transform()
{
    cv::Point2f src[4], dst[4];
    src[0] = cv::Point2f(0, height - 1);
    src[1] = cv::Point2f(width - 1, height - 1);
    src[2] = cv::Point2f(width / 2 + width / 20, 3 * height / 4);
    src[3] = cv::Point2f(width / 2 - width / 20, 3 * height / 4);
    dst[0] = cv::Point2f(0, height - 1);
    dst[1] = cv::Point2f(width - 1, height - 1);
    dst[2] = cv::Point2f(width - 1, 0);
    dst[3] = cv::Point2f(0, 0);
    transform = cv::getPerspectiveTransform(src, dst);
    inverse_transform = cv::getPerspectiveTransform(dst, src);
}

void LaneDetector::detect(cv::Mat& frame)
{
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, blurred, cv::Size(3, 3), 0);
    cv::Canny(blurred, edges, 50, 150);
    //cv::bitwise_and(edges, mask, edges);
    
    cv::warpPerspective(edges, warped, transform, cv::Size(width, height));

    //cv::dilate(edges, edges, cv::Mat(), cv::Point(-1, -1), 5);
    //cv::erode(edges, edges, cv::Mat(), cv::Point(-1, -1), 5);
    
    //cv::findContours(edges, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
    //cv::drawContours(frame, contours, -1, cv::Scalar(255, 0, 0), 5);
    
    /*cv::HoughLines(warped, hough_lines, 1, CV_PI / 180, 75, 0, 0);
    for (const auto& polar_coords : hough_lines)
    {
        float rho = polar_coords[0], theta = polar_coords[1];
        double a = std::cos(theta), b = std::sin(theta);
        double x0 = a * rho, y0 = b * rho;
        std::vector<cv::Point> warped_pts, regular_pts;
        pt1.x = cvRound(x0 - 1000 * b);
        pt1.y = cvRound(y0 + 1000 * a);
        pt2.x = cvRound(x0 + 1000 * b);
        pt2.y = cvRound(y0 - 1000 * a);
        cv::line(frame, pt1, pt2, cv::Scalar(0, 0, 255, 100), 5);
    }*/

    /*cv::HoughLinesP(edges, p_hough_lines, 1, CV_PI / 180, 75, 50, 150);
    for (const auto& l : p_hough_lines)
    {
        std::vector<cv::Point2f> warped_pts, regular_pts;
        warped_pts = {cv::Point(l[0], l[1]), cv::Point(l[2], l[3])};
        cv::perspectiveTransform(warped_pts, regular_pts, inverse_transform);
        cv::line(frame, regular_pts[0], regular_pts[1], cv::Scalar(0, 0, 255), 5);
    }*/

    cv::imshow("Lane Detector", warped);
}