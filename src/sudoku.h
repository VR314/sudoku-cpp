#ifndef SUDOKU_H
#define SUDOKU_H

#include <algorithm>
#include <string>

typedef int sudoku_board[9][9];
typedef int apply_fn(int, int, sudoku_board); // type for conciseness

//TODO: for speed, make EVERYTHING a byte
class Sudoku {
private:
public:
  sudoku_board board;
  sudoku_board orig_board;
  void printBoard();
  void iterateAndApply(apply_fn func);
  void fillWithZeroes();
  void inputFromFile(std::string filename);
  bool checkIfSolved();
  bool recursiveBacktrack(int index);
  const int SIZE = 9;
  Sudoku(::sudoku_board init) {
    std::copy(&init[0][0], &init[0][0] + 9 * 9, &board[0][0]);
    // std::copy(&board[0][0], &board[0][0] + 81, &orig_board);
  }

  Sudoku() {
    fillWithZeroes();
    // std::copy(&board[0][0], &board[0][0] + 81, &orig_board);
  }

  Sudoku(std::string filename) {
    inputFromFile(filename);
    // std::copy(&board[0][0], &board[0][0] + 81, &orig_board);
  }
};

#endif