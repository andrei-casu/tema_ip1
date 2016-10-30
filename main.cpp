#include <iostream>
#include "t1.h"
using namespace std;

void printMatrix(matrix);
void test_checkVectorInclude();
void test_checkIsIn();
void test_rotate();
void test_setOperations();
void test_bitOperations();
void test_transformMatrix();

int main(){
  cout <<"hello"<<'\n';
  //cout <<isPalindrom(1010)<<'\n';
  //cout <<(int)sumBinaryFigure(11)<<'\n';
  //cout <<fibonnaci(2)<<' '<<fibonnaci(4)<<'\n';
  //cout <<primeDivisors(30, 45)<<'\n';
  //cout <<perfectNumbers(30);
//  matrix res = primeTwins(1, 2);
//  printMatrix(res);
//  test_checkVectorInclude();
//  test_checkIsIn();
//  test_rotate();
//  test_bitOperations();
//  test_transformMatrix();
  return 0;
}

void test_transformMatrix(){
  char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG] = {
    {1, 0, 1},
    {1, 1, 1},
    {1, 1, 1}
  };
  
  transformMatrix(mat, 3, 3);
  //something
}

void test_bitOperations(){
  long numbers[] = {1, 2, 2};
  char operations[] = ">&";
  
  cout <<bitOperations(numbers, operations, 3)<<'\n';
}


void test_setOperations(){
  long sets[] = {1, 2, 2};
  char operations[] = {'U', '\\'};
  
  cout <<setOperations(sets, operations, 3)<<'\n';
}

void test_rotate(){
  matrix mat = {2, 2, {
    {1, 2},
    {3, 4}
  }};
  
  matrix res = rotate(mat, 1, 0);
  printMatrix(res);
}

void test_checkIsIn(){
  vector vec = {3, {3, 4, 6}};
  matrix mat = {3, 3, {
    {1, 2, 3},
    {3, 4, 5},
    {6, 7, 8}
  }};
  
  cout <<checkIsIn(vec, mat)<<'\n';
}

void test_checkVectorInclude(){
  vector one = {4, {4, 1, 2, 3, 0}};
  
  vector two = {5, {3, 1, 2, 0, 100}};
  
  cout <<(int)checkVectorInclude(one, two)<<'\n';
}

void printMatrix(matrix m){
  cout <<'\n'<<"lines: "<<m.lines<<' '<<"columns: "<<m.columns<<'\n'<<"values: \n";

  int i, j;
  for (i = 0; i < m.lines; ++i){
    for (j = 0; j < m.columns; ++j)
      cout <<m.values[i][j]<<' ';
    cout <<'\n';
  }
}
