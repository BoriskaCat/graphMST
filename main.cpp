#include <iostream>
#include <fstream>
#include "clGraph.h"


int main()
{
    std::ifstream file("input.txt");

    clGraph Graph(&file);

    Graph.Show();
    Graph.buildMST();
    Graph.Show();

    Graph.~clGraph();

    return 0;
}
