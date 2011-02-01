/**
  * File Name : bubbleSort.cpp
  *
  * Purpose :
  * Creation Date : 01-02-2011
  *
  * Last Modified : Tuesday 01 February 2011 12:08:26 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

void bubbleSort(int a[], int n) {
  for(int i=0; i<n; i++)
    for(int j=0; j<n-i-1; j++)
      if(a[j] > a[j+1]) swap(a[j], a[j+1]);
}

void printArr(int a[], int n) {
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;
}

int main()  {
  int a[] = {5,3,6,8,6,5,10,7,9,34,32,5,5}, n=13;
  
  cout<<"Before BubbleSort: ";
  printArr(a, n);

  bubbleSort(a, n);

  cout<<"After BubbleSort: ";
  printArr(a,n);

  return 0;
}
