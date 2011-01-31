/**
  * File Name : danglingPointer.cpp
  *
  * Purpose :
  * Creation Date : 31-01-2011
  *
  * Last Modified : Monday 31 January 2011 07:13:03 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  int *a,*b;
  int p = 5;

  a = &p;
  b = &p;

  cout<<*a<<" "<<*b<<endl;
 

  //free(a);
  //cout<<*a<<endl;

  return 0;
}
