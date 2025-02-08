#include<iostream>
using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(Rect *R1, Rect *R2) {
    Rect lap;
    
    lap.x = max(R1->x, R2->x);
    lap.y = min(R1->y, R2->y);
    lap.w = min(R1->x + R1->w, R2->x + R2->w) - lap.x;
    lap.h = lap.y - max(R1->y - R1->h, R2->y - R2->h);

    if (lap.w <= 0 || lap.h <= 0) {
        return 0;
    }

    return lap.w * lap.h;
}
