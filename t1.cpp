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
