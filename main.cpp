#include <iostream>

#define ROW 4
#define COL 5
#define DEFAULT_ARRAY_VALUES_SIZE ROW*(COL - 2)

using namespace std;

void setArrayValuesToZero(int array[ROW][COL]);
void PrintArrayValuesToConsole(int array[ROW][COL]);
void setArrayColValues(int array[ROW][COL], int colSize,
                       int arrayOrder[DEFAULT_ARRAY_VALUES_SIZE]);
int FirstselectedColNumber(int array[ROW][COL]);
int secondSelectedColNumber(int array[ROW][COL], int firstselectedNumber);
int getFirstNoneZeroValueRowNum(int array[ROW][COL], int colNumber);
int getLastZeroValueRowNum(int array[ROW][COL], int colNumber);
void swapValueInArray(int array[ROW][COL], int firstNumRow, int firstNumCol,
                      int secondNumRow, int secondNumCol);

int main() {
  int ballPipeLine[ROW][COL];
  int arrayOrderLevelOne[DEFAULT_ARRAY_VALUES_SIZE] = {1, 2, 1, 2, 2, 1,
                                                       1, 3, 3, 3, 3, 2};
  int firstSelectedRowNum;
  int firstSelectedColNum;
  int secondSelectedRowNum;
  int secondSelectedColNum;
  setArrayValuesToZero(ballPipeLine);
  // PrintArrayValuesToConsole(ballPipeLine);
  setArrayColValues(ballPipeLine, 3, arrayOrderLevelOne);

  while (true) {
    PrintArrayValuesToConsole(ballPipeLine);

    firstSelectedColNum = FirstselectedColNumber(ballPipeLine);
    firstSelectedRowNum =
        getFirstNoneZeroValueRowNum(ballPipeLine, firstSelectedColNum);

    secondSelectedColNum = secondSelectedColNumber(
        ballPipeLine,
        ballPipeLine[firstSelectedRowNum - 1][firstSelectedColNum - 1]);
    secondSelectedRowNum =
        getLastZeroValueRowNum(ballPipeLine, secondSelectedColNum);

    swapValueInArray(ballPipeLine, firstSelectedRowNum, firstSelectedColNum,
                     secondSelectedRowNum, secondSelectedColNum);
    // PrintArrayValuesToConsole(ballPipeLine);
  }
}

void setArrayValuesToZero(int array[ROW][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      array[i][j] = 0;
    }
  }
}
void PrintArrayValuesToConsole(int array[ROW][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}
void setArrayColValues(int array[ROW][COL], int colSize,
                       int arrayOrder[DEFAULT_ARRAY_VALUES_SIZE]) {
  // yellow 1
  // blue 2
  // red 3
  int count = 0;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < colSize; j++) {
      array[i][j] = arrayOrder[count];
      count++;
    }
  }
}
int FirstselectedColNumber(int array[ROW][COL]) {
  int selectedCol;
  bool canSelectCol;
  while (true) {
    cout << endl << "select your column =: ";
    cin >> selectedCol;
    // case: check column range
    if (selectedCol > 0 && selectedCol <= COL) {
      // case: check column has at least one none zero value
      for (int i = 0; i < ROW; i++) {
        if (array[i][selectedCol - 1] != 0) canSelectCol = true;
      }
      if (canSelectCol) return selectedCol;
    }

    cout << endl << "(Enter Valid Column Number)" << endl;
  }
}
int secondSelectedColNumber(int array[ROW][COL], int firstselectedNumber) {
  int selectedCol;
  while (true) {
    bool isAllColumnValueZero = true;
    bool isAllColumnValueNoneZero = true;
    cout << endl << "select your column =: ";
    cin >> selectedCol;
    // case: check column range
    if (selectedCol > 0 && selectedCol <= COL) {
      // case: check is all column value ==0
      for (int i = 0; i < ROW; i++) {
        if (array[i][selectedCol - 1] != 0) isAllColumnValueZero = false;
      }
      // case: all column value zero
      if (isAllColumnValueZero) return selectedCol;
      // case: check is all column has none zero value
      for (int i = 0; i < ROW; i++) {
        if (array[i][selectedCol - 1] == 0) isAllColumnValueNoneZero = false;
      }
      // case: all column has not (zero or none zero value)
      if (!isAllColumnValueZero && !isAllColumnValueNoneZero) {
        for (int i = 0; i < ROW; i++) {
          /* case: check is space available in the pipe and first  none zero
          value
          == firstselectedNumber  (Game Rule)*/
          if (array[i][selectedCol - 1] != 0 &&
              array[i][selectedCol - 1] == firstselectedNumber) {
            return selectedCol;
          }
        }
      }
    }

    cout << endl << "(Enter Valid Column Number)" << endl;
  }
}
int getFirstNoneZeroValueRowNum(int array[ROW][COL], int colNumber) {
  for (int i = 0; i < ROW; i++) {
    if (array[i][colNumber - 1] != 0) return i + 1;
  }
  // if any error occurred in other funtions
  return -1;
}
int getLastZeroValueRowNum(int array[ROW][COL], int colNumber) {
  for (int i = 0; i < ROW; i++) {
    if (array[i][colNumber - 1] != 0) return i;
  }
  // case: all column value == zero
  return ROW;
}
void swapValueInArray(int array[ROW][COL], int firstNumRow, int firstNumCol,
                      int secondNumRow, int secondNumCol) {
  int temp1 = array[firstNumRow - 1][firstNumCol - 1];
  int temp2 = array[secondNumRow - 1][secondNumCol - 1];
  array[firstNumRow - 1][firstNumCol - 1] = temp2;
  array[secondNumRow - 1][secondNumCol - 1] = temp1;
}