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

#endif
