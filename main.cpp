#include "Graph/Graph.h"
#include "AlgorithmABC/AlgorithmABC.h"
#include <iostream>

constexpr int SIZE = 200;
constexpr int MIN_NEIGHBORS = 1;
constexpr int MAX_NEIGHBORS = 20;
constexpr int ONLOOKERS = 28;
constexpr int SCOUTS = 2;

std::vector<Node *> australia();
std::vector<Node *> france();

int main() {
    const auto graph = new Graph(france());
    // const auto graph = new Graph(SIZE, MIN_NEIGHBORS, MAX_NEIGHBORS);
    AlgorithmABC::setColony(ONLOOKERS, SCOUTS, graph);
    AlgorithmABC::colorGraph();
    Graph::printPalette();
    graph->print();
    std::cout << std::endl << "Color count: " << graph->getColorUsed() << std::endl;
    delete graph;
    int stop = 0;
    std::cin >> stop;
    return 0;
}

std::vector<Node *> australia() {
    std::vector<Node *> nodes;
    for (int i = 0; i < 7; i++) {
        nodes.push_back(new Node(i + 1));
    }
    nodes[0]->addNeighbor(nodes[1]);
    nodes[0]->addNeighbor(nodes[3]);
    nodes[1]->addNeighbor(nodes[0]);
    nodes[1]->addNeighbor(nodes[2]);
    nodes[1]->addNeighbor(nodes[3]);
    nodes[2]->addNeighbor(nodes[1]);
    nodes[2]->addNeighbor(nodes[3]);
    nodes[2]->addNeighbor(nodes[4]);
    nodes[3]->addNeighbor(nodes[0]);
    nodes[3]->addNeighbor(nodes[1]);
    nodes[3]->addNeighbor(nodes[2]);
    nodes[3]->addNeighbor(nodes[4]);
    nodes[3]->addNeighbor(nodes[5]);
    nodes[4]->addNeighbor(nodes[2]);
    nodes[4]->addNeighbor(nodes[3]);
    nodes[4]->addNeighbor(nodes[5]);
    nodes[5]->addNeighbor(nodes[3]);
    nodes[5]->addNeighbor(nodes[4]);
    return nodes;
}

std::vector<Node *> france() {
    std::vector<Node *> nodes;
    for (int i = 0; i < 13; i++) {
        nodes.push_back(new Node(i + 1));
    }
    nodes[0]->addNeighbor(nodes[1]);
    nodes[0]->addNeighbor(nodes[2]);
    nodes[1]->addNeighbor(nodes[0]);
    nodes[1]->addNeighbor(nodes[2]);
    nodes[1]->addNeighbor(nodes[4]);
    nodes[1]->addNeighbor(nodes[5]);
    nodes[1]->addNeighbor(nodes[6]);
    nodes[2]->addNeighbor(nodes[0]);
    nodes[2]->addNeighbor(nodes[1]);
    nodes[2]->addNeighbor(nodes[3]);
    nodes[2]->addNeighbor(nodes[4]);
    nodes[3]->addNeighbor(nodes[2]);
    nodes[3]->addNeighbor(nodes[4]);
    nodes[3]->addNeighbor(nodes[9]);
    nodes[3]->addNeighbor(nodes[10]);
    nodes[4]->addNeighbor(nodes[1]);
    nodes[4]->addNeighbor(nodes[2]);
    nodes[4]->addNeighbor(nodes[3]);
    nodes[4]->addNeighbor(nodes[5]);
    nodes[4]->addNeighbor(nodes[8]);
    nodes[4]->addNeighbor(nodes[9]);
    nodes[5]->addNeighbor(nodes[1]);
    nodes[5]->addNeighbor(nodes[4]);
    nodes[5]->addNeighbor(nodes[8]);
    nodes[5]->addNeighbor(nodes[7]);
    nodes[5]->addNeighbor(nodes[6]);
    nodes[6]->addNeighbor(nodes[1]);
    nodes[6]->addNeighbor(nodes[5]);
    nodes[6]->addNeighbor(nodes[7]);
    nodes[7]->addNeighbor(nodes[5]);
    nodes[7]->addNeighbor(nodes[6]);
    nodes[7]->addNeighbor(nodes[8]);
    nodes[8]->addNeighbor(nodes[4]);
    nodes[8]->addNeighbor(nodes[5]);
    nodes[8]->addNeighbor(nodes[7]);
    nodes[8]->addNeighbor(nodes[9]);
    nodes[9]->addNeighbor(nodes[3]);
    nodes[9]->addNeighbor(nodes[4]);
    nodes[9]->addNeighbor(nodes[8]);
    nodes[9]->addNeighbor(nodes[10]);
    nodes[9]->addNeighbor(nodes[11]);
    nodes[10]->addNeighbor(nodes[3]);
    nodes[10]->addNeighbor(nodes[9]);
    nodes[10]->addNeighbor(nodes[11]);
    nodes[11]->addNeighbor(nodes[9]);
    nodes[11]->addNeighbor(nodes[10]);
    return nodes;
}