/**
  * File Name : palindrome.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 05:53:32 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string.h>

using namespace std;

bool isPalindrome (char *str) {
  int len = strlen(str);

  for(int i=0; i<len/2; i++)  if(str[i] != str[len-i-1]) return false;
  return true;
}

int main() {
  char *str = "HellolleH";
  cout<<"Is Palindrome: "<<isPalindrome(str)<<endl;
  return 0;
}
