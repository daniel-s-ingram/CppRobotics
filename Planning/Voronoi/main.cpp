#include <iostream>
#include <vector>
#include <boost/polygon/voronoi.hpp>
#include <boost/polygon/polygon.hpp>

typedef boost::polygon::point_data<int> Point;
typedef boost::polygon::segment_data<int> Segment;

int main(int argc, char** argv)
{
    std::vector<Point> points;
    std::vector<Segment> segments;
    points.push_back(Point(0, 0));
    points.push_back(Point(1, 6));
    segments.push_back(Segment(Point(-4, 5), Point(5, -1)));
    segments.push_back(Segment(Point(3, -11), Point(13, -1)));
    boost::polygon::voronoi_diagram<double> vd;
    boost::polygon::construct_voronoi(
        points.begin(),
        points.end(),
        segments.begin(),
        segments.end(),
        &vd);
    return 0;
}