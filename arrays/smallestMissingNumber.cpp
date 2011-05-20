/**
  * File Name : smallestMissingNumber.cpp
  *
  * Purpose : Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array.
  *
  * Creation Date : 20-05-2011
  *
  * Last Modified : Friday 20 May 2011 11:49:35 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <algorithm>

using namespace std;

int findSmallestMissing(int a[], int n, int m){
  int i=0,x=0;
  if(a[0] != x) return 0;

  for(i=0; i < n; i++) 
    if(a[i] == x) continue;
    else if(a[i] == x+1) x+=1;
    else return x+1;

  return x+1;
}

/** Only Works if array doesn't contain any duplicate elements **/
int findSmallestMissingBinarySearch( int a[], int l, int r){
  if(l > r) return r+1;
  
  if(l != a[l]) return l;
  
  int mid = (l+r)/2;
  if(a[mid] > mid) return findSmallestMissingBinarySearch(a, l, mid);
  else return findSmallestMissingBinarySearch(a, mid+1, r);
}

int main(){
  srand((unsigned)time(0));
  int n=10, m=13;
  int *a = new int[n];
  for(int i=0; i<n; i++) a[i] = i;
  sort(a,a+n);

  cout<<"Array is: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<", ";
  cout<<endl;

  int x = rand()%m;
  cout<<"Smallest Missing Number is: "<<findSmallestMissing(a, n, m)<<endl;

  cout<<"Smallest Missing Number O(logn) "<<findSmallestMissingBinarySearch(a, 0, n-1)<<endl;
  return 0;
}
