#include "sudoku.h"
#include <iostream>
#include <fstream>
using namespace std;

void Sudoku::printBoard() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
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

void Sudoku::inputFromFile(string filename) {
  ifstream fin(filename.c_str(), ios::in);
  if (!fin.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return;
    }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int x;
      fin >> x;
      cout << x << endl;
      board[i][j] = x;
    }
  }
  fin.close();
}