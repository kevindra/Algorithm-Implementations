/**
  * File Name : 1_largestNumLessThanX.cpp
  *
  * Purpose : Asked in my First Telephonic Interview, first question.

  * Question: Given Sorted Integer Array, and an Integer x, find largest number in the array < x.
  *
  * Creation Date : 02-02-2011
  *
  * Last Modified : Wednesday 02 February 2011 11:45:13 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

int findLargest( int a[], int p, int r, int x) {
  int mid = (p+r)/2;
  if(x <= a[0]) return -1;  //left boundary condition
  if(x > a[r]) return a[r]; //right boundary condition

  if( x == a[mid] ) {
      if( mid == 0 ) return -1; // there is no such number. 
      if( a[mid-1] == a[mid] ) return findLargest(a, p, mid-1, x);
      return a[mid-1];
  }
  else if( mid > 0 && x > a[mid-1] && x < a[mid] ) return a[mid-1];
  else if( x < a[mid] ) return findLargest(a, p, mid, x);
  else  return findLargest(a,mid+1, r, x);
}

using namespace std;

int main()  {
  int a[] = {1,2,3,4,6,7,8,9,10,11,12}, n = 11;
  int x = 4;

  cout<<"Array is: ";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;

  for(int x = 0; x < 15; x++) 
    cout<<"Largest Number less than "<<x<<" is: "<<findLargest(a, 0, n-1, x)<<endl;
  return 0;
}
