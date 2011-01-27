/**
  * File Name : removeDuplicatesFromSortedArray.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 04:02:26 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>

using namespace std;

/** returns the number of duplicates found **/
int removeDuplicates( int a[], int &n ) {
  int dups=0;

  for(int i=1; i<n; i++)  {
    if(a[i-1] == a[i]) ++dups;
    a[i-dups] = a[i];
  }
  n -= dups;
  return dups;
}

int main () {
  int a[] = {1, 2, 8, 8 , 24, 60, 60, 60, 60, 75, 100, 100,123}, n=13;
  
  cout<<"Before removing duplicates: \n";
  for(int i=0; i<n; i++)  cout<<a[i]<<", ";
  cout<<endl;

  int dups =  removeDuplicates(a,n);
  cout<<"No. of duplicates found: " <<dups<<endl;

  cout<<"After removing duplicates: \n";
  for(int i=0; i<n; i++)  cout<<a[i]<<", ";
  cout<<endl;

  return 0;
}
