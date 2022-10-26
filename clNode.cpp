#include <iostream>
#include <sstream>
#include "clNode.h"


clNode::clNode(int x_temp, int y_temp, int ID_temp)
    : clCircle(x_temp, y_temp), NodeID(ID_temp)
{
    cout << "Node constructor is completed" << endl;
}

clNode::~clNode()
{
    cout << "Node destructor is completed" << endl;
}

void clNode::Show()
{
    char ID[4];
    sprintf(ID, "%c", NodeID + 65);

    clCircle::Show();

    settextstyle(BOLD_FONT, HORIZ_DIR, 10);
    outtextxy(Getx() - 5, Gety() - 10, ID);
}
