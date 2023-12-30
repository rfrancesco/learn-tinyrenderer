#ifndef MY_RENDERING_LIBRARY_H
#define MY_RENDERING_LIBRARY_H

#include "tgaimage.h"

class Point {
public:
    int x;
    int y;

    // A bit of a hack to allow construction with anything that is castable to int
    // without complaining about narrowing (e.g. floats or doubles)
    // Probably a very bad practice.
    template <typename T> Point(T x, T y)
        : x(static_cast<int>(x)), y(static_cast<int>(y)) {};
    inline Point transpose() { return Point{y,x}; };
};

void line(Point p0, Point p1, TGAImage &image, const TGAColor &color);
inline void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor &color)
{
    line(Point{x0,y0}, Point{x1,y1}, image, color);
}

#endif