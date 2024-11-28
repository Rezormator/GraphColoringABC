#include "Graph.h"
#include "../RandomGenerator/RandomGenerator.h"
#include <windows.h>
#include <iostream>

Graph::Graph(const int size, const int minNeighbors, const int maxNeighbors)
: size(size), minNeighbors(minNeighbors), maxNeighbors(maxNeighbors) {
    generateNodes();
    connectNodes();
}

Graph::Graph(const std::vector<Node *>& nodes) : size(static_cast<int>(nodes.size())), nodes(nodes) {
}

Graph::Graph() {
}

Graph::~Graph() {
    for (const auto node : nodes) {
        delete node;
    }
}

std::vector<Node *> Graph::getNodes() const {
    return nodes;
}

int Graph::getColorUsed() const {
    int colorUsed = 0;
    for (const auto node : nodes) {
        if (node->getColor() > colorUsed) {
            colorUsed = node->getColor();
        }
    }
    return colorUsed + 1;
}

Graph *Graph::getCopy() const {
    std::vector<Node *> nodes;
    for (int i = 0; i < size; i++) {
        nodes.push_back(new Node(i + 1, this->nodes[i]->getColor()));
    }
    for (int i = 0; i < size; i++) {
        for (const auto neighbor : this->nodes[i]->getNeighbors()) {
            nodes[i]->addNeighbor(nodes[neighbor->getNumber() - 1]);
        }
    }
    return new Graph(nodes);
}

void Graph::generateNodes() {
    for (int i = 0; i < size; i++) {
        auto node = new Node(i + 1);
        nodes.push_back(node);
    }
}

void Graph::connectNodes() const {
    for (int i = 0; i < size; i++) {
        auto neighborsCount = RandomGenerator::generateInt(minNeighbors, maxNeighbors);
        while (neighborsCount != 0 && nodes[i]->getNectar() != maxNeighbors) {
            const auto neighbor = RandomGenerator::generateInt(0, size - 1);
            if (neighbor == i || nodes[neighbor]->getNectar() >= maxNeighbors || nodes[i]->contain(nodes[neighbor])) {
                continue;
            }
            nodes[i]->addNeighbor(nodes[neighbor]);
            nodes[neighbor]->addNeighbor(nodes[i]);
            neighborsCount--;
        }
    }
}

void Graph::print() const {
    for (const auto node : nodes) {
        std::cout << "Node " << node->getNumber() << ' ' << node->getNectar() << " color " << node->getColor() << " [";
        setConsoleColor(node->getColor() + 1);
        std::cout << "  ";
        setConsoleColor(0);
        std::cout << "] :";
        for (const auto neightbor : node->getNeighbors()) {
            std::cout << ' ' << neightbor->getNumber();
        }
        std::cout << std::endl;
    }
}

bool Graph::isColored() const {
    for (const auto node : nodes) {
        if (node->getColor() == -1) {
            return false;
        }
    }
    return true;
}

void Graph::setConsoleColor(const int color) {
    const auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const auto colorAttribute = color << 4 | 7;
    SetConsoleTextAttribute(hConsole, colorAttribute);
}

void Graph::printPalette() {
    std::cout << std::endl;
    for (int i = 0; i < 15; i++) {
        std::cout << " [";
        setConsoleColor(i + 1);
        std::cout << "  ";
        setConsoleColor(0);
        std::cout << "] ";
    }
    std::cout << std::endl << std::endl;
}
