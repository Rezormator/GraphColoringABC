#include "Node.h"
#include <algorithm>

Node::Node(const int number) : number(number), color(-1), nectar(0) {
}

Node::Node(const int number, const int color) : number(number), color(color), nectar(0) {
}

void Node::setColor(const int color) {
    this->color = color;
}

void Node::setNectar(const int nectar) {
    this->nectar = nectar;
}

void Node::addNeighbor(Node *neighbor) {
    neighbors.push_back(neighbor);
    nectar++;
}

int Node::getNumber() const {
    return number;
}

int Node::getColor() const {
    return color;
}

std::vector<Node *> Node::getNeighbors() const {
    return neighbors;
}

int Node::getNectar() const {
    return nectar;
}

bool Node::contain(const Node *node) const {
    return std::ranges::any_of(neighbors, [&](const auto& neighbor) {
        return neighbor == node;
    });
}
