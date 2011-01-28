/**
  * File Name : binarySearch.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 06:18:53 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int search(int *a, int num, int start, int end)  {
  if(start>end) return -1;

  int mid = (start+end+1)/2;
  
  if( num < a[mid] )  return search( a, num, start, mid-1 );
  else if( num > a[mid] ) return search( a, num, mid+1, end);
  else return mid;
}

int main() {
  int *a, n=10;
  a = (int*) malloc( sizeof(int)*n );
  for(int i=1; i<=n; i++) a[i-1] = i;
  
  int numToSearch = 8;
  int pos = search(a,numToSearch,0,n-1);
  cout<<"Found at(0-based): "<<pos<<endl;
  return 0;
}
