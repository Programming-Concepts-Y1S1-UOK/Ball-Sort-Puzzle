#include <iostream>

using namespace std;

void setArrayValuesToZero(int array[4][5]);
void PrintArrayValuesToConsole(int array[4][5]);
void setArrayColValues(int array[4][5], int colSize, int arrayOrder[12]);
int FirstselectedColNumber(int array[4][5]);
int secondSelectedColNumber(int array[4][5], int firstselectedNumber);
int getFirstNoneZeroValueRowNum(int array[4][5], int colNumber);
int getLastZeroValueRowNum(int array[4][5], int colNumber);
void swapValueInArray(int array[4][5], int firstNumRow, int firstNumCol,
                      int secondNumRow, int secondNumCol);

int main() {
  int ballPipeLine[4][5];
  int arrayOrderLevelOne[12] = {1, 2, 1, 2, 2, 1, 1, 3, 3, 3, 3, 2};
  int firstSelectedColNum;
  int secondSelectedColNum;
  int firstSelectedRowNum;
  int secondSelectedRowNum;
  setArrayValuesToZero(ballPipeLine);
  PrintArrayValuesToConsole(ballPipeLine);
  setArrayColValues(ballPipeLine, 3, arrayOrderLevelOne);
  PrintArrayValuesToConsole(ballPipeLine);
  firstSelectedColNum = FirstselectedColNumber(ballPipeLine);
  secondSelectedColNum = secondSelectedColNumber(ballPipeLine, 1);
  firstSelectedRowNum =
      getFirstNoneZeroValueRowNum(ballPipeLine, firstSelectedColNum);
  secondSelectedRowNum =
      getLastZeroValueRowNum(ballPipeLine, secondSelectedColNum);
  swapValueInArray(ballPipeLine, firstSelectedRowNum, firstSelectedColNum,
                   secondSelectedRowNum, secondSelectedColNum);
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
int FirstselectedColNumber(int array[4][5]) {
  int selectedCol;
  bool canSelectCol;
  while (true) {
    cout << endl << "select your column =: ";
    cin >> selectedCol;
    // case: check column range
    if (selectedCol > 0 && selectedCol <= 5) {
      // case: check column has at least one none zero value
      for (int i = 0; i < 4; i++) {
        if (array[i][selectedCol - 1] != 0) canSelectCol = true;
      }
      if (canSelectCol) return selectedCol;
    }

    cout << endl << "(Enter Valid Column Number)" << endl;
  }
}
int secondSelectedColNumber(int array[4][5], int firstselectedNumber) {
  int selectedCol;
  while (true) {
    bool isAllColumnValueZero = true;
    bool isAllColumnValueNoneZero = true;
    cout << endl << "select your column =: ";
    cin >> selectedCol;
    // case: check column range
    if (selectedCol > 0 && selectedCol <= 5) {
      // case: check is all column value ==0
      for (int i = 0; i < 4; i++) {
        if (array[i][selectedCol - 1] != 0) isAllColumnValueZero = false;
      }
      // case: all column value zero
      if (isAllColumnValueZero) return selectedCol;
      // case: check is all column has none zero value
      for (int i = 0; i < 4; i++) {
        if (array[i][selectedCol - 1] == 0) isAllColumnValueNoneZero = false;
      }
      // case: all column has not (zero or none zero value)
      if (!isAllColumnValueZero && !isAllColumnValueNoneZero) {
        for (int i = 0; i < 4; i++) {
          /* case: check is space available in the pipe and first  none zero
          value
          == firstselectedNumber  (Game Rule)*/
          if (array[i][selectedCol - 1] != 0 &&
              array[i][selectedCol - 1] == firstselectedNumber) {
            return selectedCol;
          } else {
            break;
          }
        }
      }
    }

    cout << endl << "(Enter Valid Column Number)" << endl;
  }
}
int getFirstNoneZeroValueRowNum(int array[4][5], int colNumber) {
  for (int i = 0; i < 4; i++) {
    if (array[i][colNumber] != 0) return i + 1;
  }
  // if any error occurred in other funtions
  return -1;
}
int getLastZeroValueRowNum(int array[4][5], int colNumber) {
  for (int i = 0; i < 4; i++) {
    if (array[i][colNumber] != 0) return i;
    // case: all column value == zero
    return 4;
  }
  // if any error occurred in other funtions
  return -1;
}
void swapValueInArray(int array[4][5], int firstNumRow, int firstNumCol,
                      int secondNumRow, int secondNumCol) {
  int temp1 = array[firstNumRow - 1][firstNumCol - 1];
  int temp2 = array[secondNumRow - 1][secondNumCol - 1];
  array[firstNumRow - 1][firstNumCol - 1] = temp2;
  array[secondNumRow - 1][secondNumCol - 1] = temp1;
}