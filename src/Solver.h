#ifndef INC_15PUZZLE_SOLVER_H
#define INC_15PUZZLE_SOLVER_H

#include <unordered_set>
#include <set>
#include "PuzzleState.h"

class Solver {
protected:
    std::vector<PuzzleState*> visited;
public:
    void addToVisited(PuzzleState* state);
    bool isVisited(PuzzleState* state);
    virtual void solve(PuzzleState* state) = 0;
};

#endif //INC_15PUZZLE_SOLVER_H
