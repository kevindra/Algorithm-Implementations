/**
  * File Name : variableArgumentsFunction.cpp
  *
  * Purpose :
  * Creation Date : 01-02-2011
  *
  * Last Modified : Tuesday 01 February 2011 12:37:36 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <stdarg.h> // this provides funtionality to variable arguments.
#include <string.h>
#include <iostream>

using namespace std;

int funct(char *arg,...){
  va_list argp;
  va_start(argp, arg);

  char *p;
  int length = strlen(arg);

  cout<<arg<<" ";
  while( (p = va_arg(argp, char*)) != NULL )  {
    cout<<p<<" ";
    length = length + strlen(p);
  }

  va_end(argp);
  return length;
}

int main()  {
  int length;
  length = funct("hello", "hi", "hey!", (char*)NULL);

  cout<<length<<endl;
  return 0;
}
