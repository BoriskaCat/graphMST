#ifndef CLLINE_H
#define CLLINE_H

#include "clDraw.h"


class clLine : public clDraw {
public:
    clLine(int x1_temp, int y1_temp, int x2_temp, int y2_temp, int color_temp);
    virtual ~clLine();

    int Getx1() { return x1; }
    int Getx2() { return x2; }
    int Gety1() { return y1; }
    int Gety2() { return y2; }

    void Show(int color);

private:
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, color = 0;
};

#endif // CLLINE_H
