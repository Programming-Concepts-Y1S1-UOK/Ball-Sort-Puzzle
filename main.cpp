#include <iostream>

#define ROW 4  // rows are fixed to 4

using namespace std;

void setArrayValuesToZero(int** array, int columnSize);//set all 2d array  elements to zero
void PrintArrayValuesToConsole(int** array, int columnSize);//print 2d array elements to terminal 
int getDifficultyFromUser(void);//easy-medium-hard
void setInitialBallPositions(int** array, int colSize, int* initialBallPositions);//set initial ball position after game started
int FirstselectedColNumber(int** array, int columnSize);//take the ball from the pipeLine(column) 
int secondSelectedColNumber(int** array, int firstselectedNumber, int columnSize);//drop the ball to pipeLine(column)
int getFirstNoneZeroValueRowNum(int** array, int colNumber);//we need to take the ball from the pipeLine top
int getLastZeroValueRowNum(int** array, int colNumber);//we need to drop the ball to the pipeLine bottom
void swapValueInArray(int** array, int firstNumRow, int firstNumCol, int secondNumRow, int secondNumCol);//2 value swap in 2d array
int getColumnSize(int gameDeficultyLevel);

int main() {
  int gameDeficultyLevel;
  int columnSize;
  gameDeficultyLevel = getDifficultyFromUser();
  columnSize = getColumnSize(gameDeficultyLevel);

  int** ballPipeLine = new int* [columnSize];  // rows are fixed to 4 
  for (int i = 0; i < ROW; i++) {
    ballPipeLine[i] = new int[columnSize];  // easy column-5, medium column-7, hard column-9
  }

  int* initialBallPositions = new int[ROW * (columnSize - 2)];//in the start we need to fill the pipelines(column) with 2 empty pipeline(column)
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
  // initialBallPositionsEasy = {1, 2, 1, 2, 2, 1, 1, 3, 3, 3, 3, 2};
  //initialBallPositionMedium={2,3,3,4,5,5,1,3,1,2,4,2,4,1,3,1,2,4,5,5}
  //initialBallPositionHard={3,5,4,4,6,4,7,7,6,1,1,2,4,7,3,5,6,3,6,7,1,2,5,2,3,5,2,1}

  int firstSelectedColNum;//ball take column position
  int firstSelectedRowNum;//ball take row position
  int secondSelectedColNum;//ball drop column position
  int secondSelectedRowNum;//ball drop row position
  setArrayValuesToZero(ballPipeLine, columnSize);
  setInitialBallPositions(ballPipeLine, (columnSize - 2), initialBallPositions);

  while (true) {
    PrintArrayValuesToConsole(ballPipeLine, columnSize);

    firstSelectedColNum = FirstselectedColNumber(ballPipeLine, columnSize);
    firstSelectedRowNum = getFirstNoneZeroValueRowNum(ballPipeLine, firstSelectedColNum);

    secondSelectedColNum = secondSelectedColNumber(ballPipeLine, ballPipeLine[firstSelectedRowNum - 1][firstSelectedColNum - 1], columnSize);
    secondSelectedRowNum = getLastZeroValueRowNum(ballPipeLine, secondSelectedColNum);

    swapValueInArray(ballPipeLine, firstSelectedRowNum, firstSelectedColNum, secondSelectedRowNum, secondSelectedColNum);
  }
}
//set all 2d array  elements to zero
void setArrayValuesToZero(int** array, int columnSize) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < columnSize; j++) {
      array[i][j] = 0;
    }
  }
}
//print 2d array elements to terminal 
void PrintArrayValuesToConsole(int** array, int columnSize) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < columnSize; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}
//three main level (easy-medium-hard )
int getDifficultyFromUser(void) {
  int choice;
  cout << "Press 1 for easy" << endl;
  cout << "Press 2 for medium" << endl;
  cout << "Press 3 for hard" << endl;
  while (true)
  {
    cout << "Now Enter Number: ";
    cin >> choice;
    if (choice > 0 && choice <= 3)
      return choice;
    cout << "(Enter Valid Input)" << endl;
  }


}
//set initial ball position after game started
void setInitialBallPositions(int** array, int colSize, int* initialBallPositions) {
  // yellow 1
  // blue 2
  // red 3
  //green 4
  //pink 5
  //dark green 6
  //purple 7
  int count = 0;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < colSize; j++) {
      array[i][j] = initialBallPositions[count];
      count++;
    }
  }
}
//take the ball from the pipeLine(column) 
int FirstselectedColNumber(int** array, int columnSize) {
  int selectedCol;
  bool canSelectCol;
  while (true) {
    cout << endl << "select your column =: ";
    cin >> selectedCol;
    // case: check column range
    if (selectedCol > 0 && selectedCol <= columnSize) {
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
int secondSelectedColNumber(int** array, int firstselectedNumber, int columnSize) {
  int selectedCol;
  while (true) {
    bool isAllColumnValueZero = true;
    bool isAllColumnValueNoneZero = true;
    cout << endl << "select your column =: ";
    cin >> selectedCol;
    // case: check column range
    if (selectedCol > 0 && selectedCol <= columnSize) {
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
int getColumnSize(int gameDeficultyLevel) {
  if (gameDeficultyLevel == 1)
    return 5;
  else if (gameDeficultyLevel == 2)
    return 7;
  else if (gameDeficultyLevel == 3)
    return 9;
  else
    return -1;
}