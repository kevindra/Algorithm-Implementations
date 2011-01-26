/**
  * File Name : reverseString.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 03:53:39 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string.h>

using namespace std;

char *reverse( char *str ) {
  int len = strlen(str);
  for(int i=0; i<len/2; i++)  swap(str[i], str[len-i-1]);
  return str;
}
int main()  {
  char s[] = "I am a good boy";
  //or you can use this also, but this is deprecated.
  //char *s = "I am a good boy.";

  char *rev = reverse(s);
  cout<<rev<<endl;
  return 0;
}
