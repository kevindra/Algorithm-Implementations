/**
  * File Name : passByReference.cpp
  *
  * Purpose :
  * Creation Date : 01-02-2011
  *
  * Last Modified : Tuesday 01 February 2011 12:52:07 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <stdlib.h>
#include <stdio.h>

/*void func1( int &a ) { //this is invalid for C but works in C++
  a += 1;
}*/

void func1(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int a=5,b=10;;
  
  printf("%d %d\n", a, b);
  func1(&a, &b);
  printf("%d %d\n", a, b);

  return 0;
}
