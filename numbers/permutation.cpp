/**
  * File Name : permutation.cpp
  *
  * Purpose :
  * Creation Date : 07-02-2011
  *
  * Last Modified : Monday 07 February 2011 03:26:13 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int *val;
void visit(int, int);

int main(){
  int n = 2;

  val = (int*) calloc(0, sizeof(int)*n);

  visit(0, n);
  
  return 0;
}

int level = -1;
void visit(int k, int n) {
  val[k]  = ++level;
  if( level == n-1 )  {
    for(int i=0; i<n; i++)  cout<<val[i]<<" ";
    cout<<endl;
    //int a; cin>>a;
  }
  else  for(int i=0; i<n; i++)  if(val[i] == 0) visit(i, n);

  level--;
  val[k] = 0;
}
