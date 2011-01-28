/**
  * File Name : reverseWordsString.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 04:57:14 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string.h>

using namespace std;

/* to reverse selected part of a string */
void reverseString (char *&s, int start, int end) {
  int len = end-start;
  for(int i=start; i<=start+len/2; i++) {
    swap(s[i], s[end-i+start]);
  }
}

char *reverseWords ( char *str ) {
  reverseString(str,0,strlen(str)-1);
  int len = strlen(str);
  int start = 0;

  for(int i=0; i<len; i++)  {
    if(str[i] == ' '){
      reverseString(str,start,i-1);
      start = i+1;
    }
    else if(i==len-1) reverseString(str,start,i);
  }

  return str; 
}

int main()  {
  char s[] = "This program is written by Kevindra Singh";
  //output should be:
  //Singh Kevindra by written is program This

  char *rev = reverseWords(s);

  cout<<"Reverse: "<<rev<<endl;
  return 0;
}
