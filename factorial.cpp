/**
  * File Name : factorial.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 12:50:24 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>

using namespace std;

int fact( int f ) {
  if( f == 0 ) return 1;
  return f*fact(f-1);
}

int main()  {
  int num = 4;
  cout<<"Factorial of "<<num<<" : "<<fact(num)<<endl;
  return 0;
}
