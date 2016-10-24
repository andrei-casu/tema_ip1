#include <iostream>
#include "t1.h"
using namespace std;

void printMatrix(matrix);

int main(){
  cout <<"hello"<<'\n';
  //cout <<isPalindrom(1010)<<'\n';
  //cout <<(int)sumBinaryFigure(11)<<'\n';
  //cout <<fibonnaci(2)<<' '<<fibonnaci(4)<<'\n';
  //cout <<primeDivisors(30, 45)<<'\n';
  //cout <<perfectNumbers(30);
  matrix res = primeTwins(1, 2);
  printMatrix(res);
  return 0;
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
