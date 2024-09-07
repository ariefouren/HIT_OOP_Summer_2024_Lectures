#include "Vertex.h"

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
