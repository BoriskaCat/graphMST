#ifndef CLNODE_H
#define CLNODE_H

#include "clCircle.h"


class clNode : public clCircle {
public:
    clNode(int x_temp, int y_temp, int num_temp);
    ~clNode();

    void Show();

private:
    int NodeID = 0;
};

#endif // CLNODE_H
