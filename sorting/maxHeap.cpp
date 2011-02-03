/**
  * File Name : maxHeap.cpp
  *
  * Purpose :
  * Creation Date : 31-01-2011
  *
  * Last Modified : Monday 31 January 2011 04:15:19 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

#define SIZE 50
int heapSize = 0;

void insertKey( int a[], int key )  {
  heapSize = heapSize + 1;
  a[heapSize-1] = key;

  int i = heapSize;
  while(i > 0 && a[i/2] < a[i]) {
    swap( a[i/2], a[i] );
    i = i/2;
  }
}


void maxHeapify ( int a[], int i, int heapSize ) {
  int left = 2*i + 1;
  int right = 2*i + 2;
  
  int largest = -1;
  if( left < heapSize && a[left] > a[i] ) largest = left;
  else largest  = i;

  if( right < heapSize && a[right] > a[largest] ) largest = right;

  if( largest != i )  {
    swap(a[largest], a[i]);
    maxHeapify(a, largest, heapSize);
  }
}

int heapExtractMax( int a[], int &heapSize ) {
  if(heapSize == 0) return -1;
  
  int MAX = a[0];
  a[0] = a[heapSize-1];
  heapSize = heapSize - 1;
  maxHeapify( a, 0, heapSize );

  return MAX;
}

void print( int a[], int n )  {
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;
}

int main()  {
  int key;
  int a[SIZE];
  int n = 0;
  while(cin>>key && key) {
    insertKey(a, key);
    n++;
  }

  print(a,n);
  return 0;
}
