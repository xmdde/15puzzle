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
    PuzzleState(short *board);
    PuzzleState(short *arr, move m);
    bool isInOpenSet;
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
    void swapOnBoard(int index1, int index2);
    void printBoard();
    void randomizeBoard();
    PuzzleState* getPredecessor();
};

#endif //INC_15PUZZLE_PUZZLESTATE_H