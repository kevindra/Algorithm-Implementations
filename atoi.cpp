/**
  * File Name : atoi.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 12:32:07 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int myatoi(char *s) {
  int number  = 0;
  
  while(*s) {
    number = (number<<3) + (number<<1) + (*s-'0');
    cout<<number<<endl;
    s++;
  }
  return number;
}

int myatoi2(char *s)  {
  int number = 0;
  int signbit = 1;
  if(*s=='-') s++, signbit = -1;

  while(*s && ((*s) >='0' && (*s) <= '9')) {
    number = (number*10) + (*s-'0');
    s++;
  }
  return signbit*number;
}

int main()  {
  cout<<myatoi2("1198")<<endl;
}
