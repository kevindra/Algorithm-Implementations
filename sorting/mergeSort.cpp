/**
  * File Name : mergeSort.cpp
  *
  * Purpose :
  * Creation Date : 31-01-2011
  *
  * Last Modified : Monday 31 January 2011 01:23:36 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <limits.h>

using namespace std;

void merge ( int a[], int p, int q, int r ) {
  int n1 = q-p+1, n2 = r-q;
  int *L  = new int[n1+1];
  int *R  = new int[n2+1];

  for(int i=0; i<n1; i++) L[i] = a[p+i];
  for(int i=0; i<n2; i++) R[i] = a[q+i+1];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  
  int i=0, j=0;

  for(int k=p; k<=r; k++) {
    if(L[i] <= R[j])  {
      a[k] = L[i];
      i++;
    }
    else  {
      a[k]  = R[j];
      j++;
    }
  }
}

void mergeSort( int a[], int p, int r )  {
  if(p < r){
    int mid = (p+r)/2;
    mergeSort(a,p,mid);
    mergeSort(a,mid+1,r);
    merge(a,p,mid,r);
  }
}

void printArr( int a[], int n ) {
  for(int i=0; i<n; i++)  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int a[] = {4,1,5,61,32,7,23,7,0,6,34};
  int n = 11;
  printArr( a , n );

  mergeSort( a , 0 , n-1 );
  printArr( a , n );

  return 0; 
}
