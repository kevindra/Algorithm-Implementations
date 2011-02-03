/**
  * File Name : findRangeInSortedArray.cpp
  *
  * Purpose :
  * Creation Date : 01-02-2011
  *
  * Last Modified : Tuesday 01 February 2011 05:46:36 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int findLowIndex(int a[], int key, int start, int end)  {
  if(start > end) return -1;
  int mid = (start+end)/2;
  
  if( key == a[mid] ) {
    if( mid == 0 || (a[mid-1] != a[mid]) )
      return mid; 
    else
      return findLowIndex(a, key, start, mid-1);
  }
  else if( key < a[mid] )
    return findLowIndex(a, key, start, mid);
  else
    return findLowIndex(a, key, mid+1, end);
}

int findHighIndex(int a[], int key, int start, int end)  {
  if(start > end) return -1;
  int mid = (start+end)/2;
  
  if( key == a[mid] ) {
    if( mid == end || (a[mid+1] != a[mid]) )
      return mid; 
    else
      return findHighIndex(a, key, mid+1, end);
  }
  else if( key < a[mid] )
    return findHighIndex(a, key, start, mid);
  else
    return findHighIndex(a, key, mid+1, end);
}

int main()  {
  int a[] = {1,1,2,2,2,2,3,3,4,4,4,4,4,5,5,5,6,7,7,7,7}, n=21;
  int toFind = 7;

  cout<<toFind<<" low index: "<<findLowIndex(a, toFind, 0, n-1)<<endl;
  cout<<toFind<<" high index: "<<findHighIndex(a, toFind, 0, n-1)<<endl;
  return 0;
}
