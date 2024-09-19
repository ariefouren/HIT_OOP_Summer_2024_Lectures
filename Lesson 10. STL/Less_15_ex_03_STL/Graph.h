#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Vertex.h"

class Graph {

public:
    Graph(int numVertices = 0);
    void addVertex(int x, int y);
    bool hasEdge(int vertex1_id, int vertex2_id) const;
    void addEdge(int vertex1_id, int vertex2_id);
    int getDegree(int vertex_id) const;
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

private:
    std::vector<Vertex> vertices;
    std::vector<std::vector<int>> adjacencyLists;
};

#endif
