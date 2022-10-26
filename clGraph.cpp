#define _USE_MATH_DEFINES
#include <sstream>
#include <iostream>
#include <cmath>

#include "clGraph.h"


clGraph::clGraph(std::ifstream* file_temp) : file(file_temp)
{
    int i = 0, j = 0, lineLength = 0;
    std::string line;

    if ((*file).is_open()) { getline((*file), line); }
    (*file).seekg(0, std::ios::beg);

    lineLength = (int) line.length();

    for (i = 0; i < lineLength; i++)
    {
        if (line[i] == ' ')
        {
            dimMat++;
        }
    }

    dimMat++;

    GraphMat = new int* [dimMat];
    for (i = 0; i < dimMat; i++)
        GraphMat[i] = new int[dimMat];

    for (int i = 0; i < dimMat; i++)
        for (int j = 0; j < dimMat; j++)
            *file >> GraphMat[i][j];

    cout << "Graph constructor is completed" << endl;

    (*file).close();
}

clGraph::~clGraph()
{
    for (int i = 0; i < dimMat; i++)
        delete[] GraphMat[i];

    if (MSTMat != nullptr)
    {
        for (int i = 0; i < dimMat; i++)
            delete[] MSTMat[i];
    }

    if (xCoord != nullptr)
    {
        delete[] xCoord;
        delete[] yCoord;
    }

    cout << "Graph destructor is completed" << endl;
}

int minKey(int key[], bool mstSet[], int dimMat)
{
    int min = INT_MAX, min_index = 0;

    for (int i = 0; i < dimMat; i++)
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }

    return min_index;
}

void clGraph::buildMST()
{
    MSTMat = new int* [dimMat];
    for (int i = 0; i < dimMat; i++)
        MSTMat[i] = new int[dimMat];

    for (int i = 0; i < dimMat; i++)
    {
        for (int j = 0; j < dimMat; j++)
            MSTMat[i][j] = 0;
    }

    int* parent = new int [dimMat];
    int* key = new int [dimMat];
    bool* mstSet = new bool [dimMat];

    for (int i = 0; i < dimMat; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int counter = 0; counter < dimMat - 1; counter++) {
        int u = minKey(key, mstSet, dimMat);
        mstSet[u] = true;

        for (int v = 0; v < dimMat; v++)
        {
            if (GraphMat[u][v] && mstSet[v] == false && GraphMat[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = GraphMat[u][v];
            }
        }
    }

    for (int i = 1; i < dimMat; i++)
        MSTMat[parent[i]][i] = GraphMat[parent[i]][i];

    for (int i = 1; i < dimMat; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (MSTMat[i][j] != 0)
                MSTMat[j][i] = MSTMat[i][j];
        }
    }

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

void buildCoord(int** xCoord, int** yCoord, int dimMat)
{
    *xCoord = new int [dimMat];
    *yCoord = new int [dimMat];

    for (int i = 0; i < dimMat; i++) {
        (*xCoord)[i] = (int) (320 + trunc(200 * cos(-1 * M_PI_2 + 2 * i * M_PI / dimMat)));
        (*yCoord)[i] = (int) (240 + trunc(200 * sin(-1 * M_PI_2 + 2 * i * M_PI / dimMat)));
    }
}

void clGraph::Show()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "");

    if (xCoord == nullptr)
        buildCoord(&xCoord, &yCoord, dimMat);

    for (int i = 0; i < dimMat; i++) {
        clNode newNode(xCoord[i], yCoord[i], i);
        newNode.Show();
        newNode.~clNode();
    }

    for (int i = 0; i < dimMat; i++)
    {
        for (int j = i; j < dimMat; j++)
        {
            if (GraphMat[i][j])
            {
                long double cosVar = (xCoord[j] - xCoord[i]) / sqrt(pow(xCoord[j] - xCoord[i], 2) + pow(yCoord[j] - yCoord[i], 2));
                long double sinVar = (yCoord[j] - yCoord[i]) / sqrt(pow(xCoord[j] - xCoord[i], 2) + pow(yCoord[j] - yCoord[i], 2));

                int color = 15;

                if (MSTMat != nullptr && MSTMat[i][j] != 0)
                    color = 3;
                else
                    color = 15;


                clEdge newEdge(xCoord[i] + 35 * cosVar, yCoord[i] + 35 * sinVar,
                    xCoord[j] - 35 * cosVar, yCoord[j] - 35 * sinVar,
                    GraphMat[i][j], color);

                newEdge.Show();
                newEdge.~clEdge();
            }
        }
    }

    readkey();
    closegraph();
}

