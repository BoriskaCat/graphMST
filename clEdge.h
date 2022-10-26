#ifndef CLEDGE_H
#define CLEDGE_H

#include "clLine.h"


class clEdge : public clLine
{
    public:
        clEdge(int x1_temp, int y1_temp, int x2_temp, int y2_temp, int weight_temp, int color_temp);
        ~clEdge();

        void Show();

    private:
        int weight = 0, color = 15;
};

#endif // CLEDGE_H
