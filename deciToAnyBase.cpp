/**
  * File Name : deciToAnyBase.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 03:28:13 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char *deciToAnyBase( int num, int base )  {
  char s[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *ret = new char;

  while(num)  {
    int d = num%base;
    char c[2]; c[0] = s[d], c[1] ='\0';
    strcat(ret, c);
    num/=base;
  }
  reverse(ret,ret+strlen(ret));
  return ret;
}

int main () {
  cout<<deciToAnyBase(1001231,21)<<endl;  
  return 0;
}
