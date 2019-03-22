#include "lane_detector.h"

LaneDetector::LaneDetector(int height, int width) : height(height), width(width)
{
    init_perspective_transform();
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
    cv::warpPerspective(edges, warped, transform, cv::Size(width, height));
    cv::HoughLinesP(warped, houghp_lines, 1, CV_PI / 180, 50, 15, 150);
    for (const auto& l : houghp_lines)
    {
        std::vector<cv::Point2f> warped_pts, regular_pts;
        warped_pts = {cv::Point2f(l[0], l[1]), cv::Point2f(l[2], l[3])};
        cv::perspectiveTransform(warped_pts, regular_pts, inverse_transform);
        float m = (regular_pts[1].y - regular_pts[0].y) / (regular_pts[1].x - regular_pts[0].x);
        float b = regular_pts[0].y - m * regular_pts[0].x;
        cv::Point p1(width / 2, m * (width / 2) + b), p2;
        if (m < 0)
            p2 = cv::Point(0, b);
        else
            p2 = cv::Point(width, m * width + b);
        cv::line(frame, regular_pts[0], regular_pts[1], cv::Scalar(0, 0, 255), 5);
    }
}