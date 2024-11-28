#pragma once

#include <vector>
#include "../Utils.h"

class Node {
private:
    int number;
    int color;
    int nectar;
    std::vector<Node *> neighbors;
public:
    explicit Node(int number);
    explicit Node(int number, int color);
    void setColor(int color);
    void setNectar(int nectar);
    void addNeighbor(Node *neighbor);
    NODISCARD int getNumber() const;
    NODISCARD int getColor() const;
    NODISCARD int getNectar() const;
    NODISCARD std::vector<Node *> getNeighbors() const;
    NODISCARD bool contain(const Node *node) const;
};
