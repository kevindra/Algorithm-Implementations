/**
  * File Name : trim.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 12:25:57 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string.h>

using namespace std;

void trim ( char *str ) {
  int idx = 0;
  for(int i=0; i<strlen(str); i++) if(str[i] != ' ') str[idx] = str[i], idx++;
  str[idx] ='\0';
}

int main() {
  char s[] = "  Hello   How r u  ";
  cout<<"\""<<s<<"\""<<endl;
  trim(s);
  cout<<"\""<<s<<"\""<<endl;
  return 0;
}
