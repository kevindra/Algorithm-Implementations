/**
  * File Name : reverseBits.cpp
  *
  * Purpose :
  * Creation Date : 30-01-2011
  *
  * Last Modified : Sunday 30 January 2011 10:56:07 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int reverseBits( int num )  {
  int temp = 0;
  for(int i=sizeof(int)*8-1; i>0; i--)  {
    temp |= (num&1);
    temp <<= 1;
    num >>= 1;
  }
  temp |= (num&1);
  return temp;
}

int main()  {
  int a = 10;
  cout<<reverseBits(a)<<endl;
  return 0;
}
