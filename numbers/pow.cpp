/**
  * File Name : pow.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 12:58:59 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>

using namespace std;

/** power function - brute force method **/
int pow1 ( int a, int x ) {
  if(x==1) return a;
  return a*pow1(a,x-1);
}

/** power function - divide and conquer method **/
int pow2 ( int a, int x ) {
  if( x==1 ) return a;

  if(x%2==0){
    int p = pow2(a,x/2);
    return p*p;
  }
  else {
    int p = pow2(a,x/2);
    return a*p*p;
  }
}

int main () {
  int a = 2, x = 10;
  cout<<"Power of "<<a<<", "<<x<<" : "<<pow2(a,x)<<endl;
  return 0;
}
