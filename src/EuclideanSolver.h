#ifndef INC_15PUZZLE_EUCLIDEANSOLVER_H
#define INC_15PUZZLE_EUCLIDEANSOLVER_H

#include "Solver.h"
#include <queue>
#include <set>
#include <unordered_set>
#include <cmath>

struct euclideanComparePuzzleState {
    bool operator () (PuzzleState* state1, PuzzleState* state2) {
        int cost1 = state1->getDepth();
        int cost2 = state2->getDepth();
        for (int i = 0; i < 16; i++) {
            if (state1->getBoard()[i] != 0) {
                int xPos = i % 4;
                int yPos = i / 4;
                int xDest = (state1->getBoard()[i] - 1) % 4;
                int yDest = (state1->getBoard()[i] - 1) / 4;
                cost1 += sqrt((xDest - xPos)*(xDest - xPos) + (yDest - yPos)*(yDest - yPos));
            }
        }
        for (int i = 0; i < 16; i++) {
            if (state2->getBoard()[i] != 0) {
                int xPos = i % 4;
                int yPos = i / 4;
                int xDest = (state2->getBoard()[i] - 1) % 4;
                int yDest = (state2->getBoard()[i] - 1) / 4;
                cost2 += sqrt((xDest - xPos)*(xDest - xPos) + (yDest - yPos)*(yDest - yPos));
            }
        }
        return cost1 > cost2;
    }
};

class EuclideanSolver : public Solver {
private:
    std::vector<PuzzleState*> visited;
    std::priority_queue<PuzzleState*, std::vector<PuzzleState*>, euclideanComparePuzzleState> openSet; //unvisited nodes, nbhs to visited
public:
    EuclideanSolver();
    void solve(PuzzleState* state) override;
    void printPath(PuzzleState* state);
};

#endif //INC_15PUZZLE_EUCLIDEANSOLVER_H
