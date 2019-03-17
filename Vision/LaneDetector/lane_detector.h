#include <vector>
#include <opencv2/opencv.hpp>

class LaneDetector
{
    public:
        LaneDetector(int height, int width);
        void detect(cv::Mat& frame);

    private:
        void init_roi_mask(int height, int width);

        cv::Mat gray, blurred, edges, corners, mask;
        std::vector<std::vector<cv::Point> > contours;
        std::vector<cv::Vec2f> hough_lines;
        std::vector<cv::Vec4i> p_hough_lines;
};