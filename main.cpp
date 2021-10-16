#include <iostream>

#define ROW 4  // rows are fixed to 4
#define COL 5
#define DEFAULT_ARRAY_VALUES_SIZE ROW*(COL - 2)

using namespace std;

void setArrayValuesToZero(int** array);//set all 2d array  elements to zero
void PrintArrayValuesToConsole(int** array);//print 2d array elements to terminal 
void setInitialBallPositions(int** array, int colSize, int* initialBallPositions);//set initial ball position after game started
int FirstselectedColNumber(int** array);//take the ball from the pipeLine(column) 
int secondSelectedColNumber(int** array, int firstselectedNumber);//drop the ball to pipeLine(column)
int getFirstNoneZeroValueRowNum(int** array, int colNumber);//we need to take the ball from the pipeLine top
int getLastZeroValueRowNum(int** array, int colNumber);//we need to drop the ball to the pipeLine bottom
void swapValueInArray(int** array, int firstNumRow, int firstNumCol, int secondNumRow, int secondNumCol);//2 value swap in 2d array

int main() {
  int** ballPipeLine = new int* [ROW];  // rows are fixed to 4 
  for (int i = 0; i < ROW; i++) {
    ballPipeLine[i] = new int[COL];  // easy col-5, medium col-7, hard col-9
  }

  int* initialBallPositions = new int[ROW * (COL - 2)];//in the start we need to fill the pipelines(column) with 2 empty pipeline(column)
  initialBallPositions[0] = 1;
  initialBallPositions[1] = 2;
  initialBallPositions[2] = 1;
  initialBallPositions[3] = 2;
  initialBallPositions[4] = 2;
  initialBallPositions[5] = 1;
  initialBallPositions[6] = 1;
  initialBallPositions[7] = 3;
  initialBallPositions[8] = 3;
  initialBallPositions[9] = 3;
  initialBallPositions[10] = 3;
  initialBallPositions[11] = 2;
  // initialBallPositions = {1, 2, 1, 2, 2, 1, 1, 3, 3, 3, 3, 2};

  int firstSelectedColNum;//ball take column position
  int firstSelectedRowNum;//ball take row position
  int secondSelectedColNum;//ball drop column position
  int secondSelectedRowNum;//ball drop row position
  setArrayValuesToZero(ballPipeLine);
  setInitialBallPositions(ballPipeLine, 3, initialBallPositions);

  while (true) {
    PrintArrayValuesToConsole(ballPipeLine);

    firstSelectedColNum = FirstselectedColNumber(ballPipeLine);
    firstSelectedRowNum = getFirstNoneZeroValueRowNum(ballPipeLine, firstSelectedColNum);

    secondSelectedColNum = secondSelectedColNumber(ballPipeLine, ballPipeLine[firstSelectedRowNum - 1][firstSelectedColNum - 1]);
    secondSelectedRowNum = getLastZeroValueRowNum(ballPipeLine, secondSelectedColNum);

    swapValueInArray(ballPipeLine, firstSelectedRowNum, firstSelectedColNum, secondSelectedRowNum, secondSelectedColNum);
  }
}
//set all 2d array  elements to zero
void setArrayValuesToZero(int** array) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      array[i][j] = 0;
    }
  }
}
//print 2d array elements to terminal 
void PrintArrayValuesToConsole(int** array) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}
//set initial ball position after game started
void setInitialBallPositions(int** array, int colSize, int* initialBallPositions) {
  // yellow 1
  // blue 2
  // red 3
  int count = 0;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < colSize; j++) {
      array[i][j] = initialBallPositions[count];
      count++;
    }
  }
}
//take the ball from the pipeLine(column) 
int FirstselectedColNumber(int** array) {
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
//drop the ball to pipeLine(column)
int secondSelectedColNumber(int** array, int firstselectedNumber) {
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
//we need to take the ball from the pipeLine top
int getFirstNoneZeroValueRowNum(int** array, int colNumber) {
  for (int i = 0; i < ROW; i++) {
    if (array[i][colNumber - 1] != 0) return i + 1;
  }
  // if any error occurred in other funtions
  return -1;
}
//we need to drop the ball to the pipeLine bottom
int getLastZeroValueRowNum(int** array, int colNumber) {
  for (int i = 0; i < ROW; i++) {
    if (array[i][colNumber - 1] != 0) return i;
  }
  // case: all column value == zero
  return ROW;
}
//2 value swap in 2d array
void swapValueInArray(int** array, int firstNumRow, int firstNumCol, int secondNumRow, int secondNumCol) {
  int temp1 = array[firstNumRow - 1][firstNumCol - 1];
  int temp2 = array[secondNumRow - 1][secondNumCol - 1];
  array[firstNumRow - 1][firstNumCol - 1] = temp2;
  array[secondNumRow - 1][secondNumCol - 1] = temp1;
}