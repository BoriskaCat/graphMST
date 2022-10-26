#include "clLine.h"

clLine::clLine(int x1_temp, int y1_temp, int x2_temp, int y2_temp, int color_temp)
        : x1(x1_temp), y1(y1_temp), x2(x2_temp), y2(y2_temp), color(color_temp)
{
    cout << "Line constructor is completed" << endl;
}

clLine::~clLine()
{
    cout << "Line destructor is completed" << endl;
}

void clLine::Show(int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
}
