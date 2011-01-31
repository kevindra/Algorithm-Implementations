/**
  * File Name : heapsort.cpp
  *
  * Purpose :
  * Creation Date : 31-01-2011
  *
  * Last Modified : Monday 31 January 2011 02:54:39 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

void maxHeapify( int a[], int i, int heapSize ) {
  int left = 2*i+1;
  int right = 2*i+2;
  
  int largest = -1;

  if( left < heapSize && a[left] > a[i] ) largest = left;
  else largest = i;

  if( right < heapSize && a[right] > a[largest] ) largest = right;

  if( largest != i ) {
    swap( a[largest], a[i] );
    maxHeapify( a, largest, heapSize );
  }
}

void buildMaxHeap( int a[], int heapSize){
  for(int i=heapSize-1; i>=0; i--)
    maxHeapify(a, i, heapSize);
}

void heapSort( int a[], int n ) {
  int heapSize = n;
  buildMaxHeap( a, heapSize ); 

  for(int i=n-1; i>=0; i--) {
    swap( a[i], a[0] );
    heapSize -= 1;
    maxHeapify( a, 0, heapSize );
  }
}

void printArr( int a[], int n ) {
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;
}

int main() {
  int a[] = {4,1,5,61,32,7,23,7,0,6,34};
  int n = 11;

  cout<<"Before Sorting: "<<endl;
  printArr( a , n );

  heapSort( a , n );

  cout<<"After Sorting: "<<endl;
  printArr( a , n );

  return 0;   
}
