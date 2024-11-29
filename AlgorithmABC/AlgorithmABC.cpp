#include "AlgorithmABC.h"
#include <algorithm>
#include <iostream>
#include "../RandomGenerator/RandomGenerator.h"

int AlgorithmABC::onlookerCount;
int AlgorithmABC::scoutCount;
Graph *AlgorithmABC::graph;

void AlgorithmABC::setColony(const int onlookerCount, const int scoutCount, Graph *graph) {
    AlgorithmABC::onlookerCount = onlookerCount;
    AlgorithmABC::scoutCount = scoutCount;
    AlgorithmABC::graph = graph;
}

void AlgorithmABC::colorGraph() {
    int iterationsCount = 0;
    std::vector<Node *> nodes = graph->getNodes();
    std::ranges::sort(nodes, [](const Node* a, const Node* b) { return a->getNectar() > b->getNectar(); });
    while (!nodes.empty()) {
        auto onlookerNodes = getOnlookerNodes(nodes);
        while (!onlookerNodes.empty()){
            const auto probabilityDistribution = calculateProbabilityDistribution(onlookerNodes);
            const auto probability = RandomGenerator::generateDouble(0, 1);
            int nodeNumber = 0;
            for (const auto nodeProbability : probabilityDistribution) {
                if (probability > nodeProbability) {
                    nodeNumber++;
                }
                else {
                    break;
                }
            }
            colorNodeNeighbors(onlookerNodes[nodeNumber]);
            colorNode(onlookerNodes[nodeNumber]);
            onlookerNodes.erase(onlookerNodes.begin() + nodeNumber);
        }
        for (int i = 0; i < scoutCount; i++) {
            if (nodes.empty()) {
                break;
            }
            const auto randomNode = RandomGenerator::generateInt(0, static_cast<int>(nodes.size()) - 1);
            colorNodeNeighbors(nodes[randomNode]);
            colorNode(nodes[randomNode]);
            nodes.erase(nodes.begin() + randomNode);
        }
        iterationsCount++;
        if (graph->isColored()) {
            std::cout << "Iteration: " << iterationsCount << " Colors count: " << graph->getColorUsed() << std::endl;
        }
    }
}

std::vector<Node *> AlgorithmABC::getOnlookerNodes(std::vector<Node *> &nodes) {
    int nodeCount = onlookerCount;
    if (nodes.size() < nodeCount) {
        nodeCount = static_cast<int>(nodes.size());
    }
    std::vector<Node *> onlookerNodes;
    for (int i = 0; i < nodeCount; i++) {
        onlookerNodes.push_back(nodes[i]);
    }
    nodes.erase(nodes.begin(), nodes.begin() + nodeCount);
    return onlookerNodes;
}

std::vector<double> AlgorithmABC::calculateProbabilityDistribution(const std::vector<Node *> &nodes) {
    std::vector<double> probabilityDistribution;
    const auto nodesCount = nodes.size();
    double nectarTotal = 0;
    for (const auto node : nodes) {
        nectarTotal += node->getNectar();
    }
    for (int i = 0; i < nodesCount; i++) {
        const auto nodeProbability = nodes[i]->getNectar() / nectarTotal;
        if (probabilityDistribution.empty()) {
            probabilityDistribution.push_back(nodeProbability);
        }
        else {
            probabilityDistribution.push_back(probabilityDistribution[i - 1] + nodeProbability);
        }
    }
    return probabilityDistribution;
}

void AlgorithmABC::colorNode(Node *node) {
    const auto neighbors = node->getNeighbors();
    std::vector colors(node->getNectar() + 1, true);
    for (const auto neighbor : neighbors) {
        if (neighbor->getColor() != -1) {
            colors[neighbor->getColor()] = false;
        }
    }
    for (int i = 0; i < node->getNectar() + 1; i++) {
        if (colors[i]) {
            node->setColor(i);
            break;
        }
    }
}

void AlgorithmABC::colorNodeNeighbors(Node *node) {
    node->setColor(-1);
    for (const auto neighbor : node->getNeighbors()) {
        colorNode(neighbor);
    }
}
