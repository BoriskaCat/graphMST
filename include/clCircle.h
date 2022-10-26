#ifndef CLCIRCLE_H
#define CLCIRCLE_H

#include "clDraw.h"


class clCircle : public clDraw {
public:
    clCircle(int x0, int y0);
    virtual ~clCircle();

    int Getx() { return x; }
    int Gety() { return y; }

    void Show();

private:
    int x = 0, y = 0;
    const int r = 25;
};

#endif // CLCIRCLE_H
