#include "tgaimage.h"
#include "my_rendering_library.h"

void line(Point p0, Point p1, TGAImage &image, const TGAColor &color)
{
    bool steep = false;
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;

    if (std::abs(dy) > std::abs(dx))
    {
        steep = 1;
        p0 = p0.transpose();
        p1 = p1.transpose();
        std::swap(dx, dy);
    }

    if (p0.x > p1.x)
        std::swap(p0,p1);

    float m = (p1.y - p0.y) / ((float)(p1.x - p0.x));
    for (int x=p0.x; x <= p1.x; x++)
    {
        int y = p0.y + m*(x - p0.x);
        if (!steep)
            image.set(x,y,color);
        else
            image.set(y,x,color);
    }
}