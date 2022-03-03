#include "sudoku.h"
#include <functional>
#include <iostream>
using namespace std;

// sudoku text files source: http://lipas.uwasa.fi/~timan/sudoku/

// pass by reference: void f(int (&array)[rows][cols]), access as `array`, call
// as f(array)
// pass by pointer: void f(int (*array)[5][10]), access as
// `(*array)[i][j]`, call as f(&array)

int testApply(int i, int j, sudoku_board b) {
  cout << i << " " << j << "  " << b[i][j] << endl;
  return 0;
}

int main() {
  Sudoku s = Sudoku("sudokus/test.in");
  s.printBoard();
  return 0;
}