/**
  * File Name : lcm.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 03:42:33 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int gcd (int a, int b)  {
  if(b==0) return a;
  return gcd(b,a%b);
}

int lcm (int a, int b) {
  return (a*b)/gcd(a,b);
}

int main()  {
  cout<<lcm(3,6)<<endl;
}
