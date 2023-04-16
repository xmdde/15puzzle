#include "ManhattanSolver.h"
#include "EuclideanSolver.h"

int main() {
    auto* state = new PuzzleState();
    ManhattanSolver manhattanSolver;
    manhattanSolver.solve(state);
    //EuclideanSolver euclideanSolver;
    //euclideanSolver.solve(state);
    return 0;
}
