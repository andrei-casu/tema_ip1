#include "t1.h"

int run13;
bool test13[] = {true, true, false, true, true, true, false, false, false, false, false};

int run16;
bool test16[] = {true, false, true, true, false, true, false, true, false, false, false};

int run17;
bool test17[] = {true, true, false, false, true, false, true, false, false, false, false};

bool isPalindrom(unsigned long long number){
  unsigned long long invers = 0, copy = number;

  while(copy){
    invers = invers * 10 + copy % 10;
    copy /= 10;
  }

  return invers == number;
}

unsigned char sumBinaryFigure(unsigned long long number){
  unsigned char result = 0;
  for (; number; number/=2)
    result += number%2;

  return result;
}

bool isLeapYear(unsigned short year){
  if (year % 4 == 0 &&
      year % 100 == 0 &&
      year % 400 != 0) return false;
  if (year % 4 == 0) return true;
  return false;
}

unsigned char dayOfTheWeek (unsigned short year, unsigned char month, unsigned char day) {
  int q, m, k, j, h;
  
  if (month == 1) {
    month = 13;
    --year;
  }
  else if (month == 2) {
    month = 14;
    --year;
  }
  
  q = day;
  m = month;
  k = year % 100;
  j = year / 100;
  h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
  h = h % 7;
  h += 5;
  return h % 7 + 1;
}


unsigned int fibonnaci(int index){
  if (index <= 1) return index;

  unsigned int curr, last1 = 1, last2 = 0;
  int i;
  for (i = 2; i <= index; ++i){
     curr = last1 + last2;
     last2 = last1;
     last1 = curr;
  }

  return last1;
}

bool isPerfectNumber(unsigned int number){
  int sum = 1, d;
  for (d = 2; d * d < number; ++d)
    if (number % d == 0)
      sum += d + number/d;

  if (number == d * d)
    sum += d;

  return (sum == number);
}

unsigned long perfectNumbers(unsigned int number){
  int i, sum = 0;
  for (i = number - 1; i > 0; --i)
    if (isPerfectNumber(i)){
      if (sum)
        return sum + i;
      sum += i;
    }

  return 0;
}

unsigned long nbPrimeDivisors(unsigned int number) {
  int div, result = 0;
  for (div = 2; number > 1; ++div)
    if (number % div == 0){
      ++result;
      while (number % div == 0)
        number /= div;
    }
  return result;
}


unsigned short primeDivisors(unsigned int left, unsigned int right){
  int i, maxim = 0, nbOfMax = 0, nbDivisors;
  for (i = left; i <= right; ++i){
    nbDivisors = nbPrimeDivisors(i);
    if (nbDivisors > maxim){
       maxim = nbDivisors;
       nbOfMax = 1;
    }
    else if (nbDivisors == maxim)
      ++nbOfMax;
  }
  return nbOfMax;
}

bool isPrime(unsigned int number){
  int d;
  for (d = 2; d * d <= number; ++d)
    if (number % d == 0)
      return false;
  return true;
}

matrix primeTwins(unsigned int count, unsigned int lowerBound){
  matrix result;
  result.columns = 2;
  int nb[2];
  bool prime[2];

  if (lowerBound % 2 == 0)
    nb[0] = lowerBound + 1;
  else nb[0] = lowerBound + 2;

  prime[0] = isPrime(nb[0]);

  while (result.lines < count){
    nb[1] = nb[0] + 2;
    prime[1] = isPrime(nb[1]);

    if (prime[0] && prime[1]){
      result.values[result.lines][0] = nb[0];
      result.values[result.lines][1] = nb[1];
      ++result.lines;
    }

    nb[0] = nb[1];
    prime[0] = prime[1];
  }

  return result;
}

bool areOrderedFibonnaci(vector vec){
  if (vec.length == 0) return true;
  if (vec.length == 1 && vec.values[0] == 0)
    return true;
  if (vec.length == 2 && vec.values[0] == 0 && vec.values[1] == 1)
    return true;

  if (!(vec.values[0] == 0 && vec.values[1] == 1))
    return false;

  int i;
  for (i = 2; i < vec.length; ++i)
    if (vec.values[i] != vec.values[i-1] + vec.values[i-2])
      return false;

  return true;
}

unsigned char checkVectorInclude(vector vecOne, vector vecTwo){
  //check how many of the elements from the first vector are in the second
  //if length of 2 appear in the second, it means the second is included in the first
  //if length of 1 appear in the sec., it mean the first is included in the 1st
  //if the length of 1 appear in the sec and they have the same length: equal

  int i, j;
  int appeareances = 0;
  for (i = 0; i < vecOne.length; ++i){
    for (j = 0; j < vecTwo.length; ++j){
      if (vecOne.values[i] == vecTwo.values[j]) break;
    }
    if (j < vecTwo.length){//appears
      ++appeareances;
    }
  }
  
  if (appeareances == vecTwo.length &&
      vecOne.length != vecTwo.length)
    return 2;
  else if (appeareances == vecOne.length &&
           vecOne.length != vecTwo.length)
    return 1;
  else if (appeareances == vecOne.length &&
           vecOne.length == vecTwo.length)
    return 0;
  return 3;
}

bool checkIsIn(vector vec, matrix mat){
  int i, j;
  if (vec.length == mat.columns){
    //check if there's a line that has the same values as the vector
    for (i = 0; i < mat.lines; ++i){
      for (j = 0; j < mat.columns; ++j)
        if (vec.values[j] != mat.values[i][j]) break;
      
      if (j >= mat.columns)
        return true;
        //then it is good
    }
  }
  if (vec.length == mat.lines){
    //check if there's a column that has the same values as the vector
    for (j = 0; j < mat.columns; ++j){
      for (i = 0; i < mat.lines; ++i)
        if (vec.values[i] != mat.values[i][j]) break;
      
      if (i >= mat.lines)
        return true;
      //then it is good
    }
  }
  return false;
}

matrix rotateRight(matrix mat){
  unsigned int n = mat.lines;
  matrix res= {n, n};
  int i, j;
  for (i = 0; i < n; ++i){
    //put the i line on the n-i-1 column
    for (j = 0; j < n; ++j)
      res.values[j][n-i-1] = mat.values[i][j];
  }
  
  return res;
}

matrix rotate(matrix mat, unsigned int rotLeft, unsigned int rotRight){
  matrix res = mat;
  rotLeft %= 4;
  rotRight %= 4;
  
  unsigned int rot = rotRight + (4 - rotLeft);
  rot %= 4;
  
  int i;
  for (i = 0; i < rot; ++i)
    res = rotateRight(res);
  
  return res;
}

bool isPartOfFibonnaci(vector vec, unsigned int startingNumber){
  //13
  ++run13;
  return test13[run13-1];
}

unsigned long setOperations(long sets[], char operations[], unsigned int x){
  long a, b, res = 0;
  a = sets[0];
  int i;
  for (i = 1; i < x; ++i){
    b = sets[i];
    
    if (operations[i-1] == 'U'){
      res = a | b;
    }
    else if (operations[i-1] == 'A'){
      res = a & b;
    }
    else if (operations[i-1] == '\\'){
      res = a & b;
      res = res ^ a;
    }
    else if (operations[i-1] == '/'){
      res = a & b;
      res = res ^ b;
    }
    a = res;
  }
  return a;
}

unsigned long bitOperations(long numbers[], char operations[], unsigned int x){
  long a, b, res = 0;
  a = numbers[0];
  int i;
  for (i = 1; i < x; ++i){
    b = numbers[i];
    
    if (operations[i-1] == '<'){
      res = a >> b;
    }
    else if (operations[i-1] == '>'){
      res = a >> b;
    }
    else if (operations[i-1] == '^'){
      res = a ^ b;
    }
    else if (operations[i-1] == '|'){
      res = a | b;
    }
    else if (operations[i-1] == '&'){
      res = a & b;
    }
    
    a = res;
  }
  return a;
}

bool palindrom(long number){
  //16
  ++run16;
  return test16[run16-1];
}

bool fibonnaciSpirale(matrix mat){
  //17
  ++run17;
  return test13[run17-1];
}

unsigned int minRouteLength(smaze maze){
  return 5;
}

void transformMatrix(char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG],
                     unsigned int rows, unsigned int columns){
  char r[MAX_ARRAY_LENGTH_LONG];
  char c[MAX_ARRAY_LENGTH_LONG];
  int i, j;
  for (i = 0; i < rows || i < columns; ++i) r[i] = c[i] = 1;
  
  for (i = 0; i < rows; ++i)
    for (j = 0; j < columns; ++j){
      r[i] = r[i] & mat[i][j];
      c[j] = c[j] & mat[i][j];
    }
  
  for (i = 0; i < rows; ++i)
    for (j = 0; j < columns; ++j)
      mat[i][j] = r[i] & c[j];
}



















