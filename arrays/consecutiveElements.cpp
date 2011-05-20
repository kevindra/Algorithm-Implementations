/**
  * File Name : consecutiveElements.cpp
  *
  * Purpose : Given an unsorted array of numbers, write a function that returns true if array consists of consecutive numbers.
  *
  * Creation Date : 20-05-2011
  *
  * Last Modified : Friday 20 May 2011 12:57:02 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <algorithm>

using namespace std;

bool checkConsecutive(int a[], int n){
  int mn = *min_element(a, a+n);
  int mx = *max_element(a, a+n);

  if(mx-mn+1 == n){
    int *d = new int[n];
    for(int i=0; i<n; i++)  d[a[i]-mn] = 1;
    for(int i=0; i<n; i++) if(d[i] != 1) return false;
    return true;
  }
  return false;
}

int main(){
  int a[] = {5,2,3,1,4}, n = 5;

  cout<<"Are Consecutive?: "<<checkConsecutive(a, n)<<endl;
  return 0;
}
