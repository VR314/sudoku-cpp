#include <iostream>
#include <functional>
using namespace std;

// pass by reference: void f(int (&array)[rows][cols]), access as `array`, call
// as f(array)
// pass by pointer: void f(int (*array)[5][10]), access as
// `(*array)[i][j]`, call as f(&array)

void printByReference(int (&array)[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      array[i][j] = 0;
      cout << "x[" << i << "][" << j << "]: ";
      cout << array[i][j] << endl;
    }
  }
}

void printByPointer(int (*array)[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      (*array)[i][j] = 0;
      cout << "x[" << i << "][" << j << "]: ";
      cout << (*array)[i][j] << endl;
    }
  }
}

void fillWithZeroes(int (*array)[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      (*array)[i][j] = 0;
    }
  }
}

void iterateAndApply(int (*array)[9][9],
                     int (*func)(int, int, int (*array)[9][9])) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      (*func)(i, j, array);
    }
  }
}

//TODO: make object oriented

int main() {
  int x[9][9];

  // iterateAndApply(x);
  return 0;
}