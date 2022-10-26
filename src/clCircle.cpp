#include "clCircle.h"


clCircle::clCircle(int x0, int y0) : x(x0), y(y0)
{
    cout << "Circle constructor is completed" << endl;
}

clCircle::~clCircle()
{
    cout << "Circle destructor is completed" << endl;
}

void clCircle::Show()
{
    circle(x,y,r);
}
