/**
  * File Name : findMaxOfThree.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 04:09:57 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int main()  {
  int a,b,c;
  a=15, b=22, c=14;

  int mx = (a>b)?(a>c?a:c):(b>c?b:c);
  cout<<"Max : "<<mx<<endl;
  return 0;
}
