#ifndef INC_15PUZZLE_PUZZLESTATE_H
#define INC_15PUZZLE_PUZZLESTATE_H

#include <vector>

void myswap(short* arr, int index1, int index2);

enum move {
    UP, DOWN, RIGHT, LEFT
};

class PuzzleState {
private:
    short* board;
    int depth;
    PuzzleState* predecessor;
public:
    PuzzleState();
    explicit PuzzleState(short *board);
    PuzzleState(const short *arr, move m);
    int getDepth();
    void setDepth(int d);
    int getGapPos();
    void moveGap(move);
    void setPredecessor(PuzzleState *p);
    bool isGoal() const;
    std::vector<PuzzleState*> getNeighbours();
    short* getBoard();
    bool operator==(const PuzzleState& state) const;
    bool operator!=(const PuzzleState& state) const;
    ~PuzzleState();
    void printBoard();
    void randomizeBoard();
    PuzzleState* getPredecessor();

    short movedNum();

    void randomizeCompletely();

    bool solvable();
};

#endif //INC_15PUZZLE_PUZZLESTATE_H