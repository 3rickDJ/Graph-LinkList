#pragma once
#include "NodeAdj.h"

class NodeGraph {
  public:
    int value;
    int visited;
    NodeAdj *adj;
    NodeGraph *next;
    //initializer
    NodeGraph();
    //print all adjacency list
    void printAdj();
    //true if elm is in adj, otherwise false
    bool isAdj(int elm);
};
