#include "Graph.h"
#include <vector>
using namespace std;

Graph::Graph(int numVertices) : 
    vertices(numVertices), 
    adjacencyLists(numVertices) {}

void Graph::addVertex(int x, int y) {
    int vId = vertices.size();
    Vertex v(vId, x, y);
    vertices.push_back(v);

    vector<int> adjList; // adjacency list for vertex v
    adjacencyLists.push_back(adjList);
}

bool Graph::hasEdge(int vertex1_id, int vertex2_id) const {
    for (int neighbor : adjacencyLists[vertex1_id]) {
        if (neighbor == vertex2_id) {
            return true;
        }
    }
    return false;
}

void Graph::addEdge(int vertex1_id, int vertex2_id) {
    if (!hasEdge(vertex1_id, vertex2_id)) {
        adjacencyLists[vertex1_id].push_back(vertex2_id);
        adjacencyLists[vertex2_id].push_back(vertex1_id);
    }
}

int Graph::getDegree(int vertex_id) const {
    return adjacencyLists[vertex_id].size();
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (int i = 0; i < graph.vertices.size(); ++i) {
        os << graph.vertices[i] << 
            " Degree: " << graph.getDegree(i) <<
            " Neighbors: ";
        for (int neighbor : graph.adjacencyLists[i]) {
            os << graph.vertices[neighbor] << " ";
        }
        os << std::endl;
    }
    return os;
}
