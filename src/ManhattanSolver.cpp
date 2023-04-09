#include "ManhattanSolver.h"
#include <iostream>

void ManhattanSolver::solve(PuzzleState* state) {
    state->setDepth(0);
    visited.push_back(state); //closedset
    openSet.push(state);
    state->isInOpenSet = true;
    std::vector<PuzzleState*> help;
    help.push_back(state);

    while (!openSet.empty()) {
        if (openSet.top()->isGoal()) {
            std::cout << "PATH FOUND";
            printPath(openSet.top());
            return;
        }
        auto x = openSet.top();
        std::vector<PuzzleState*> nbhs = x->getNeighbours();
        visited.push_back(x);
        openSet.pop();

        for (auto i : nbhs) {
            if (isVisited(i)) {
                continue;
            }
            int tentativeDepth = x->getDepth() + 1;
            bool tentBetter = false;
            bool inHelpSet = false;

            for (auto v : help) {
                if (*v == *i) {
                    inHelpSet = true;
                    i = v; //????
                }
            }

            if (!inHelpSet) { //(!i->isInOpenSet)
                openSet.push(i);
                help.push_back(i);
                i->isInOpenSet = true;
                tentBetter = true;
            } else {
                if (tentativeDepth < i->getDepth())
                    tentBetter = true;
            }
            if (tentBetter) {
                i->setPredecessor(x); //
                i->setDepth(tentativeDepth);
            }
        }
        //std::cout << openSet.size() << std::endl;
    }
    return;
}

void ManhattanSolver::printPath(PuzzleState* state) { //temp od tylu
    std::cout << "\nPath (reversed): \n";
    PuzzleState* curr = state;
    int d = curr->getDepth();
    for (int i = 0; i < d; i++) {
        curr->printBoard();
        curr = curr->getPredecessor();
    }
}

int ManhattanSolver::heuristicCost(PuzzleState* state) {
    int cost = 0;
    for (int i = 0; i < 16; i++) {
        if (state->getBoard()[i] != 0) {
            int xPos = i % 4;
            int yPos = i / 4;
            int xDest = (state->getBoard()[i] - 1) % 4;
            int yDest = (state->getBoard()[i] - 1) / 4;
            cost += abs(xPos - xDest) + abs(yPos - yDest);
        }
    }
    return cost;
}

ManhattanSolver::ManhattanSolver() {

}

