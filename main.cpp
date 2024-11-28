#include "Graph/Graph.h"
#include "AlgorithmABC/AlgorithmABC.h"
#include <iostream>

std::vector<Node *> france();

int main() {
    std::cout << "Enter color count: ";
    int maxColor;
    std::cin >> maxColor;
    std::cout << "Enter max iteration count: ";
    int maxIteration;
    std::cin >> maxIteration;
    std::cout << std::endl;

    const auto graph = new Graph(200, 1, 20);
    // const auto graph = new Graph(france());

    int bestColorCount = -1;
    auto bestColoring = new Graph;
    for (int i = 0; i < maxIteration; i++) {
        const auto graphCopy = graph->getCopy();
        AlgorithmABC::setColony(28, 2, graphCopy);
        AlgorithmABC::colorGraph();
        if (bestColorCount > graphCopy->getColorUsed() || bestColorCount == -1) {
            bestColorCount = graphCopy->getColorUsed();
            bestColoring = graphCopy->getCopy();
        }
        delete graphCopy;
        if (bestColorCount <= maxColor) {
            break;
        }
    }
    delete graph;
    Graph::printPalette();
    bestColoring->print();
    std::cout << std::endl << "Color count: " << bestColoring->getColorUsed() << std::endl;
    delete bestColoring;

    int stop = 0;
    std::cin >> stop;
    return 0;
}

std::vector<Node *> france() {
    std::vector<Node *> nodes;
    for (int i = 0; i < 22; i++) {
        nodes.push_back(new Node(i + 1));
    }
    nodes[0]->addNeighbor(nodes[1]);
    nodes[0]->addNeighbor(nodes[21]);
    nodes[1]->addNeighbor(nodes[0]);
    nodes[1]->addNeighbor(nodes[2]);
    nodes[1]->addNeighbor(nodes[10]);
    nodes[1]->addNeighbor(nodes[21]);
    nodes[2]->addNeighbor(nodes[1]);
    nodes[2]->addNeighbor(nodes[10]);
    nodes[2]->addNeighbor(nodes[9]);
    nodes[2]->addNeighbor(nodes[4]);
    nodes[3]->addNeighbor(nodes[4]);
    nodes[4]->addNeighbor(nodes[2]);
    nodes[4]->addNeighbor(nodes[3]);
    nodes[4]->addNeighbor(nodes[5]);
    nodes[4]->addNeighbor(nodes[9]);
    nodes[5]->addNeighbor(nodes[4]);
    nodes[5]->addNeighbor(nodes[9]);
    nodes[5]->addNeighbor(nodes[12]);
    nodes[5]->addNeighbor(nodes[13]);
    nodes[5]->addNeighbor(nodes[6]);
    nodes[6]->addNeighbor(nodes[5]);
    nodes[6]->addNeighbor(nodes[13]);
    nodes[6]->addNeighbor(nodes[7]);
    nodes[6]->addNeighbor(nodes[8]);
    nodes[7]->addNeighbor(nodes[8]);
    nodes[7]->addNeighbor(nodes[6]);
    nodes[7]->addNeighbor(nodes[13]);
    nodes[8]->addNeighbor(nodes[6]);
    nodes[8]->addNeighbor(nodes[7]);
    nodes[9]->addNeighbor(nodes[2]);
    nodes[9]->addNeighbor(nodes[4]);
    nodes[9]->addNeighbor(nodes[5]);
    nodes[9]->addNeighbor(nodes[12]);
    nodes[9]->addNeighbor(nodes[10]);
    nodes[10]->addNeighbor(nodes[1]);
    nodes[10]->addNeighbor(nodes[2]);
    nodes[10]->addNeighbor(nodes[9]);
    nodes[10]->addNeighbor(nodes[12]);
    nodes[10]->addNeighbor(nodes[16]);
    nodes[10]->addNeighbor(nodes[15]);
    nodes[10]->addNeighbor(nodes[11]);
    nodes[10]->addNeighbor(nodes[21]);
    nodes[11]->addNeighbor(nodes[21]);
    nodes[11]->addNeighbor(nodes[10]);
    nodes[11]->addNeighbor(nodes[15]);
    nodes[11]->addNeighbor(nodes[14]);
    nodes[12]->addNeighbor(nodes[10]);
    nodes[12]->addNeighbor(nodes[9]);
    nodes[12]->addNeighbor(nodes[5]);
    nodes[12]->addNeighbor(nodes[13]);
    nodes[12]->addNeighbor(nodes[17]);
    nodes[12]->addNeighbor(nodes[16]);
    nodes[13]->addNeighbor(nodes[7]);
    nodes[13]->addNeighbor(nodes[6]);
    nodes[13]->addNeighbor(nodes[5]);
    nodes[13]->addNeighbor(nodes[12]);
    nodes[13]->addNeighbor(nodes[17]);
    nodes[14]->addNeighbor(nodes[11]);
    nodes[14]->addNeighbor(nodes[15]);
    nodes[14]->addNeighbor(nodes[18]);
    nodes[15]->addNeighbor(nodes[11]);
    nodes[15]->addNeighbor(nodes[10]);
    nodes[15]->addNeighbor(nodes[16]);
    nodes[15]->addNeighbor(nodes[18]);
    nodes[15]->addNeighbor(nodes[14]);
    nodes[16]->addNeighbor(nodes[15]);
    nodes[16]->addNeighbor(nodes[10]);
    nodes[16]->addNeighbor(nodes[12]);
    nodes[16]->addNeighbor(nodes[17]);
    nodes[16]->addNeighbor(nodes[19]);
    nodes[16]->addNeighbor(nodes[18]);
    nodes[17]->addNeighbor(nodes[13]);
    nodes[17]->addNeighbor(nodes[12]);
    nodes[17]->addNeighbor(nodes[16]);
    nodes[17]->addNeighbor(nodes[19]);
    nodes[17]->addNeighbor(nodes[20]);
    nodes[18]->addNeighbor(nodes[14]);
    nodes[18]->addNeighbor(nodes[15]);
    nodes[18]->addNeighbor(nodes[16]);
    nodes[18]->addNeighbor(nodes[19]);
    nodes[19]->addNeighbor(nodes[18]);
    nodes[19]->addNeighbor(nodes[17]);
    nodes[19]->addNeighbor(nodes[16]);
    nodes[19]->addNeighbor(nodes[20]);
    nodes[20]->addNeighbor(nodes[17]);
    nodes[20]->addNeighbor(nodes[19]);
    nodes[21]->addNeighbor(nodes[0]);
    nodes[21]->addNeighbor(nodes[1]);
    nodes[21]->addNeighbor(nodes[10]);
    nodes[21]->addNeighbor(nodes[11]);
    return nodes;
}