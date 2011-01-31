/**
  * File Name : insertionSort.cpp
  *
  * Purpose :
  * Creation Date : 31-01-2011
  *
  * Last Modified : Monday 31 January 2011 12:59:51 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

void insertionSort( int a[], int n )  {
  for(int i=1; i<n; i++)  {
    int j=i-1, key = a[i];
    while( j >= 0 && a[j] > key ) a[j+1] = a[j], j--;
    a[j+1] = key;
  }
}

void printArr(int a[], int n) {
  for(int i=0; i<n; i++)  cout<<a[i]<<" ";
  cout<<endl;
}

int main()  {
  int a[] = {5,6,3,5,6,8,3,1,3,5}, n=10;
  
  printArr(a,n);

  insertionSort(a, n);
  
  printArr(a,n);
  return 0;
}
