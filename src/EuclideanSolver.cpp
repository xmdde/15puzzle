#include "EuclideanSolver.h"
#include <iostream>
#include <stack>

EuclideanSolver::EuclideanSolver() = default;

void EuclideanSolver::solve(PuzzleState* state) {
    std::cout << "Initial puzzle state: \n";
    state->printBoard();
    state->setDepth(0);
    visited.push_back(state); //closedset
    openSet.push(state);
    std::vector<PuzzleState*> help;
    help.push_back(state);

    while (!openSet.empty()) {
        if (openSet.top()->isGoal()) {
            printPath(openSet.top());
            std::cout << "\nNumber of visited states: " << visited.size() << "\n";
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

            if (!inHelpSet) {
                openSet.push(i);
                help.push_back(i);
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
    }
    return;
}

void EuclideanSolver::printPath(PuzzleState* state) {
    std::cout << "To solve: \n";
    PuzzleState* curr = state;
    int d = curr->getDepth();
    std::stack<short> path;
    for (int i = 0; i < d; i++) {
        path.push(curr->movedNum());
        curr = curr->getPredecessor();
    }
    while (!path.empty()) {
        std::cout << "Move " << path.top() << "\n";
        path.pop();
    }
}
