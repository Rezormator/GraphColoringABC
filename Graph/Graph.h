#pragma once

#include <vector>
#include "../Node/Node.h"

class Graph {
private:
    int size;
    int minNeighbors;
    int maxNeighbors;
    std::vector<Node *> nodes;
    static void setConsoleColor(int color) ;
public:
    explicit Graph(int size, int minNeighbors, int maxNeighbors);
    explicit Graph(const std::vector<Node *>& nodes);
    explicit Graph();
    ~Graph();
    NODISCARD std::vector<Node *> getNodes() const;
    NODISCARD int getColorUsed() const;
    NODISCARD Graph *getCopy() const;
    void generateNodes();
    void connectNodes() const;
    void print() const;
    NODISCARD bool isColored() const;
    static void printPalette();
};
