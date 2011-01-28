/**
  * File Name : isBSubsetA.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 11:41:21 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string.h>

using namespace std;

int getIndex( char c )  {
  if(c>='A' && c<='Z') return c-'A';
  else if(c>='a' && c<='z') return c-'a'+26;
  return -1;
}

bool isBSubsetA( char *s1, char *s2 ) {
  unsigned long long bitmap = 0;

  for(int i=0; i<strlen(s1); i++) bitmap |= (1<<getIndex(s1[i])); 

  for(int i=0; i<strlen(s2); i++) if( !(bitmap&(1<<getIndex(s2[i]))) ) return false;

  return true;
}

int main() {
  char *a = "ABCEF";
  char *b = "BCD";

  cout<<isBSubsetA(a,b)<<endl;
  return 0;
}
