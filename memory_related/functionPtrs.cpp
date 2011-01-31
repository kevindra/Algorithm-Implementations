/**
  * File Name : functionPtrs.cpp
  *
  * Purpose :
  * Creation Date : 31-01-2011
  *
  * Last Modified : Monday 31 January 2011 07:31:24 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int func()  {
  cout<<"Hello";
}

int main()  {
  int (*fp)();
  fp = func;

  //call
  (*fp)();
  //or
  fp();
  return 0;
}
