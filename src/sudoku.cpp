#include "sudoku.h"
#include <iostream>
using namespace std;

void Sudoku::printBoard() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = 9;
      cout << "x[" << i << "][" << j << "]: ";
      cout << board[i][j] << endl;
    }
  }
}

void Sudoku::iterateAndApply(apply_fn func) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      (*func)(i, j, board);
    }
  }
}

void Sudoku::fillWithZeroes() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = 0;
    }
  }
}