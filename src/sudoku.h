#ifndef SUDOKU_H
#define SUDOKU_H

#include <algorithm>
typedef int sudoku_board[9][9];
typedef int(apply_fn)(int, int, sudoku_board); // type for conciseness

class Sudoku {
private:
public:
  void printBoard();

  void iterateAndApply(apply_fn func);
  void fillWithZeroes();

  const int SIZE = 9;
  sudoku_board board;
  Sudoku(::sudoku_board init) {
    std::copy(&init[0][0], &init[0][0] + 9 * 9, &board[0][0]);
  }

  Sudoku() { fillWithZeroes(); }
};

#endif