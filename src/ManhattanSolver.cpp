#include "ManhattanSolver.h"
#include <iostream>
#include <stack>

void ManhattanSolver::solve(PuzzleState* state) {
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

void ManhattanSolver::printPath(PuzzleState* state) {
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

