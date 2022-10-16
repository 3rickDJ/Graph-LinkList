#pragma once

class NodeAdj {
  public:
    int value;
    NodeAdj *next;
    // initializer
    NodeAdj();
    static NodeAdj *find(NodeAdj *inicio, int elm);
    static void printList(NodeAdj *inicio);
};
