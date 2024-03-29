#include "gtest/gtest.h"
#include "PuzzleState.h"
#include "ManhattanSolver.h"

class Tests : public ::testing::Test {
public:
    short testarr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 13, 14, 15, 12};
};

TEST_F(Tests, generateStateTest) {
    short arr[16] = {2, 3, 4, 5, 6, 7, 8, 1, 9, 10, 11, 12, 13, 14, 15, 0};
    PuzzleState state = *new PuzzleState(arr);
    for (int i = 0; i < 16; i++) {
        EXPECT_EQ(arr[i], state.getBoard()[i]);
    }
}

TEST_F(Tests, neighboursTest) {
    PuzzleState s(testarr);
    s.printBoard();
    std::vector<PuzzleState*> n = s.getNeighbours();
    EXPECT_EQ(n.size(), 3);
    for (auto i : n)
        i->printBoard();
}

TEST_F(Tests, swapTest) {
    PuzzleState up(testarr, UP);
    EXPECT_EQ(up.getBoard()[7], 0);
    EXPECT_EQ(up.getBoard()[11], 8);

    PuzzleState down(testarr, DOWN);
    EXPECT_EQ(down.getBoard()[11], 12);
    EXPECT_EQ(down.getBoard()[15], 0);

    PuzzleState l(testarr, LEFT);
    EXPECT_EQ(l.getBoard()[10], 0);
    EXPECT_EQ(l.getBoard()[11], 11);
}

TEST_F(Tests, interpretMoveTest) {
    PuzzleState state(testarr);
    PuzzleState nextState(testarr, UP);
    nextState.setPredecessor(&state);
    EXPECT_EQ(nextState.movedNum(), 8);
}

TEST_F(Tests, solvableStateTest) {
    short arr[16] = {2, 3, 4, 5, 6, 7, 8, 1, 9, 10, 11, 12, 13, 14, 15, 0};
    PuzzleState state(arr);
    EXPECT_EQ(state.solvable(), true);
}

TEST_F(Tests, randomizeTest) {
    PuzzleState *state = new PuzzleState();
    if (state->solvable()) {
        ManhattanSolver manhattanSolver;
        manhattanSolver.solve(state);
    }
    //EXPECT_EQ(state.solvable(), true);
}