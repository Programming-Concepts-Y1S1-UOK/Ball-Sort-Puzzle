#include <iostream>

using namespace std;

void setArrayValuesToZero(int array[4][5]);
void PrintArrayValuesToConsole(int array[4][5]);
void setArrayColValues(int array[4][5], int colSize, int arrayOrder[12]);

int main() {
  int ballPipeLine[4][5];
  int arrayOrderLevelOne[12] = {1, 2, 1, 2, 2, 1, 1, 3, 3, 3, 3, 2};
  setArrayValuesToZero(ballPipeLine);
  PrintArrayValuesToConsole(ballPipeLine);
  setArrayColValues(ballPipeLine, 3, arrayOrderLevelOne);
  PrintArrayValuesToConsole(ballPipeLine);
}

void setArrayValuesToZero(int array[4][5]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      array[i][j] = 0;
    }
  }
}

void PrintArrayValuesToConsole(int array[4][5]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}
void setArrayColValues(int array[4][5], int colSize, int arrayOrder[12]) {
  // yellow 1
  // blue 2
  // red 3
  int count = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < colSize; j++) {
      array[i][j] = arrayOrder[count];
      count++;
    }
  }
}
