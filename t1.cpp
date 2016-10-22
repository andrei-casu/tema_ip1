#include "t1.h"

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

unsigned char dayOfTheWeek(unsigned short year,
                           unsigned char month,
                           unsigned char day){
  return 0;
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
