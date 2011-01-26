/**
  * File Name : memAllocate2DArray.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 01:50:13 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
  int **m,r,c;
  r=5,c=2;

  /** double dimensional array allocation **/
  m = (int**)malloc(sizeof(int**)*r);
  for(int i=0;i<r;i++) m[i] = (int*)malloc(sizeof(int*)*c);


  for(int i=0;i<r;i++) for(int j=0;j<c;j++) m[i][j] = j;
  for(int i=0;i<r;i++){ for(int j=0;j<c;j++) cout<<m[i][j]<<" "; cout<<endl; } 


  /** single dimensional memory allocation **/
  int *m1,n;
  n=10;
  m1 = (int*) malloc(sizeof(int)*n);

  for(int i=0; i<n;i++) m1[i] = i;

  cout<<endl;
  for(int i=0;i<n;i++) cout<<m1[i]<<" ";
  cout<<endl;
  return 0;
}
