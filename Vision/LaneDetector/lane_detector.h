#include <vector>
#include <opencv2/opencv.hpp>

class LaneDetector
{
    public:
        LaneDetector(int height, int width);
        void detect(cv::Mat& frame);

    private:
        void init_roi_mask();
        void init_perspective_transform();

        cv::Mat gray, blurred, edges, corners, mask, transform, inverse_transform, warped;
        std::vector<std::vector<cv::Point> > contours;
        std::vector<cv::Vec2f> hough_lines;
        std::vector<cv::Vec4i> p_hough_lines;
        int height, width;
};