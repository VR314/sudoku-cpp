#include "sudoku.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void Sudoku::printBoard() {
  const string HORIZ_DIVIDER = "-------------------------";
  cout << endl << HORIZ_DIVIDER << endl;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (j % 3 == 0) {
        cout << "| ";
      }
      cout << board[i][j] << " ";
    }
    cout << "|" << endl;
    if (i % 3 == 2 && i != 8) {
      cout << HORIZ_DIVIDER << endl;
    }
  }

  cout << HORIZ_DIVIDER << endl << endl;
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
    cerr << "Could not open the file - '" << filename << "'" << endl;
    return;
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int x;
      fin >> x;
      board[i][j] = x;
    }
  }
  fin.close();
}

bool duplicate(vector<int> v) {
  return std::adjacent_find(v.begin(), v.end()) != v.end();
}

bool unsolved(vector<int> v) {
  return std::find(v.begin(), v.end(), 0) != v.end();
}

// check rows, columns, and squares
bool Sudoku::checkIfSolved() {
  vector<int> horiz{};
  vector<int> vert{};
  vector<int> square{};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      horiz.push_back(board[i][j]);
      vert.push_back(board[j][i]);
    }

    if (unsolved(horiz) || unsolved(vert)) {
      cerr << "UNSOLVED" << endl;
      return false;
    } else if (duplicate(horiz) || duplicate(vert)) {
      cerr << "DUPLICATE FOUND" << endl;
      return false;
    }

    horiz = {};
    vert = {};
  }

  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      square.push_back(board[i][j]);
      square.push_back(board[i + 1][j]);
      square.push_back(board[i + 2][j]);
      square.push_back(board[i][j + 1]);
      square.push_back(board[i + 1][j + 1]);
      square.push_back(board[i + 2][j + 1]);
      square.push_back(board[i][j + 2]);
      square.push_back(board[i + 1][j + 2]);
      square.push_back(board[i + 2][j + 2]);

      if (unsolved(square)) {
        cerr << "UNSOLVED" << endl;
        return false;
      } else if (std::adjacent_find(square.begin(), square.end()) !=
                 square.end()) {
        cerr << "DUPLICATE IN SQUARE" << endl;
        for (int x : square) {
          cerr << x;
        }
        return false;
      }

      square = {};
    }
  }
  
  cerr << "SOLVED SUDOKU" << endl;
  return true;
}