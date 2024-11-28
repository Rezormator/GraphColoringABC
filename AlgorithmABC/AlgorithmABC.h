#pragma once
#include "../Graph/Graph.h"

class AlgorithmABC {
private:
    static int onlookerCount;
    static int scoutCount;
    static Graph *graph;
    static std::vector<Node *> getOnlookerNodes(std::vector<Node *> &nodes);
    static std::vector<double> calculateProbabilityDistribution(const std::vector<Node *> &nodes);
    static void colorNode(Node *node);
    static void colorNodeNeighbors(Node *node);
public:
    static void setColony(int onlookerCount, int scoutCount, Graph *graph);
    static void colorGraph();
};
