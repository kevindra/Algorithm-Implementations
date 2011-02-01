/**
  * File Name : quickSort.cpp
  *
  * Purpose :
  * Creation Date : 01-02-2011
  *
  * Last Modified : Tuesday 01 February 2011 10:47:45 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

/*int partition( int a[], int l, int r )  {
  int pivot = a[r];
  int i = l;

  for( int j=l; j<r; j++ ) {
    if( a[j] <= pivot ) i++;

    swap(a[i], a[j]);
  }
  swap(a[i+1], a[r]);

  return i+1;
}*/

int partition( int a[], int low, int high ) {
  int left, right;
  int pivot_item;
  int pivot;

  pivot_item = a[low];
  pivot = left = low;
  right = high;

  while ( left < right ) {
    /* Move left while item < pivot */
    while( a[left] <= pivot_item ) left++;
    /* Move right while item > pivot */
    while( a[right] > pivot_item ) right--;
    if ( left < right ) swap(a[left],a[right]);
    }
  /* right is final position for the pivot */
  a[low] = a[right];
  a[right] = pivot_item;
  return right;
}


void printArr( int a[], int n ) {
  for(int i=0; i<n; i++)  cout<<a[i]<<" ";
  cout<<endl;
}

void quickSort( int a[], int l, int r ) {
  if( l < r ) {  
    int q = partition(a, l, r);
    quickSort(a, l, q-1);
    quickSort(a, q+1, r);
  }
}


int main()  {
  int a[] = {9,5,6,7,8,4,2,4,5,1}, n=10;

  printArr(a, n);

  quickSort(a, 0, n-1);

  printArr(a, n);

  return 0;
}
