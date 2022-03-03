#ifndef SUDOKU_H
#define SUDOKU_H

#include <algorithm>
#include <string>

typedef int sudoku_board[9][9];
typedef int apply_fn(int, int, sudoku_board); // type for conciseness

class Sudoku {
private:
public:
  sudoku_board board;
  void printBoard();
  void iterateAndApply(apply_fn func);
  void fillWithZeroes();
  void inputFromFile(std::string filename);
  bool checkIfSolved();
  const int SIZE = 9;
  Sudoku(::sudoku_board init) {
    std::copy(&init[0][0], &init[0][0] + 9 * 9, &board[0][0]);
  }

  Sudoku() { fillWithZeroes(); }
  Sudoku(std::string filename) { inputFromFile(filename); }
};

#endif