#include "clEdge.h"

clEdge::clEdge(int x1_temp, int y1_temp, int x2_temp, int y2_temp, int weight_temp, int color_temp)
    : clLine(x1_temp, y1_temp, x2_temp, y2_temp, color_temp), weight(weight_temp), color(color_temp)
{
    cout << "Edge constructor is completed" << endl;
}

clEdge::~clEdge()
{
    cout << "Edge destructor is completed" << endl;
}

void clEdge::Show()
{
    char EdgeWeight[4];
    sprintf(EdgeWeight, "%d", weight);

    clLine::Show(color);

    setcolor(15);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
    outtextxy((Getx1() + Getx2()) / 2, (Gety1() + Gety2()) /2, EdgeWeight);
}
