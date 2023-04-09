#ifndef INC_15PUZZLE_SOLVER_H
#define INC_15PUZZLE_SOLVER_H

#include <unordered_set>
#include <set>
#include "PuzzleState.h"

class Solver {
// closedset
protected:
    std::vector<PuzzleState*> visited;
    //std::unordered_set<PuzzleState> visited;
public:
    void addToVisited(PuzzleState* state);
    bool isVisited(PuzzleState* state);
    //int getSizeOfVisitedList();
    virtual void solve(PuzzleState* state) = 0; //args
};

#endif //INC_15PUZZLE_SOLVER_H