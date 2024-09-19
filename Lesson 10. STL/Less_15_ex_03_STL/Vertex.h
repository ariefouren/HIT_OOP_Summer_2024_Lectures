#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

class Vertex {
private:
    int id;
    int x_pos;
    int y_pos;

public:
    Vertex(int id = 0, int x = 0, int y = 0);
    int getId() const;
    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex);
};
Vertex::Vertex(int id, int x, int y) : 
    id(id), x_pos(x), y_pos(y) {}

int Vertex::getId() const {
    return id;
}

std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
    os << "Vertex " << 
        vertex.id << " (" << vertex.x_pos << ", " << vertex.y_pos << ")";
    return os;
}

#endif
