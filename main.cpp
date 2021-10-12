#include <iostream>

using namespace std;

void setArrayValuesToZero(int array[4][5]);
void PrintArrayValuesToConsole(int array[4][5]);

int main() {
  int ballPipeLine[4][5];
  setArrayValuesToZero(ballPipeLine);
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
