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
    //true if elm is in adj, otherwise false
    bool isAdj(int elm);
    //print all adjacency list
    void printAdj();
    static NodeGraph* find(NodeGraph* inicio, int elm);
    static void printList(NodeGraph* inicio);
};
