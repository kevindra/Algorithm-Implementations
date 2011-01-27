/**
  * File Name : sumDigitsInAStatement.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 07:03:54 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int main() {
  int num = 12345;
  int sum =0;

  while(num)sum+=num%10,num/=10;
  cout<<"Sum digits: "<<sum<<endl;
  return false;
}
