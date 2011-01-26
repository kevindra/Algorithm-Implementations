/**
  * File Name : permutation.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Thursday 27 January 2011 12:46:36 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
bool nextPermutation( T *&a, int start, int end ) {
  int len = end-start+1;
  int j = len-1;
  if( j<=0 ) return false;

  while( j > 0 && a[j] <= a[--j] );

  if( a[j+1] <= a[j] )  {
    reverse (a+start, a+end);
    return false;
  }
  
  int k = len;
  
  while ( a[--k] <= a[j] );

  swap ( a[k], a[j] );
  reverse (a+j+1, a+end);

  return true; 
}

int main()  {
  int *a, n = 4;
  a = new int [n];
  for(int i=1; i<=n; i++) a[i-1] = i;

  sort(a,a+n);

  int cnt = 0;
  do {
    for(int i=0; i<n; i++)  cout<<a[i]<<" ";
    cout<<endl;
    cnt += 1;
  } while( nextPermutation(a,0,n) );

  cout<<"Total Permutations: "<<cnt<<endl;
  return 0;
}
