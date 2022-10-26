#ifndef CLGRAPH_H
#define CLGRAPH_H

#include <fstream>
#include "clNode.h"
#include "clEdge.h"


class clGraph {
public:
    clGraph(std::ifstream* fileVar);
	virtual ~clGraph();

	void buildMST();

	void Show();

private:
    std::ifstream* file = nullptr;
    int** GraphMat = nullptr;
	int** MSTMat = nullptr;
	int* xCoord = nullptr;
	int* yCoord = nullptr;
	int dimMat = 0;
};

#endif // CLGRAPH_H
