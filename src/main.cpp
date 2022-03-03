#include "sudoku.h"
#include <functional>
#include <iostream>
using namespace std;

// sudoku text files source: http://lipas.uwasa.fi/~timan/sudoku/

// pass by reference: void f(int (&array)[rows][cols]), access as `array`, call
// as f(array)
// pass by pointer: void f(int (*array)[5][10]), access as
// `(*array)[i][j]`, call as f(&array)

// ANSI color escape seuences: https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
void clearConsole() {
  printf("\033c");
}

int main() {
  Sudoku s = Sudoku("sudokus/test.in");
  clearConsole();
  s.printBoard();
  s.checkIfSolved();
  return 0;
}