/**
  * File Name : gcd.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 03:38:24 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int gcd ( int a, int b )  {
  if(b==0) return a;
  return gcd(b,a%b);
}

int main (){
  cout<<gcd(9,15)<<endl;
}
