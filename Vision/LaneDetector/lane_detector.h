#include <vector>
#include <opencv2/opencv.hpp>

class LaneDetector
{
    public:
        LaneDetector(int height, int width);
        void detect(cv::Mat& frame);

    private:
        void init_perspective_transform();

        cv::Mat gray, blurred, edges, transform, inverse_transform, warped;
        std::vector<cv::Vec4i> houghp_lines;
        int height, width;
};