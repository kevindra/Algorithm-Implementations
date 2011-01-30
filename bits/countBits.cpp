/**
  * File Name : countBits.cpp
  *
  * Purpose :
  * Creation Date : 30-01-2011
  *
  * Last Modified : Sunday 30 January 2011 10:31:45 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int numBits( int n ) {
  int bits = 0;
  while(n) {
    bits += n&1;
    n>>=1;
  }
  return bits;
}

int main()  {
  int num = 5;
  int bits = numBits(num);
  cout<<"Number of bits: "<<bits<<endl;
  return 0;
}
