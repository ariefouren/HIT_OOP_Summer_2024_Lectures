#include <iostream>
#include "Graph.h"

int main() {
    const int numOfVertices = 5;
    Graph graph;

    // add vertices
    for (int i = 0; i < numOfVertices; ++i) {
        graph.addVertex(i * 2, i * 3);
    }
    // add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
        
    std::cout << "Graph:" << std::endl;
    std::cout << graph;

    return 0;
}
