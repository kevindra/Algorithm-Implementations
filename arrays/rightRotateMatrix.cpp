/**
  * File Name : rightRotateMatrix.cpp
  *
  * Purpose : Rotate the matrix 90 degree clockwise
  *
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 06:18:53 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int **allocate2D(int r, int c){
  int **m = (int**) malloc(sizeof(int)*r*c);
  for(int i=0; i<r; i++) m[i] = (int*)malloc(sizeof(int)*c);
  return m;
}

int **rotate(int **a, int n){
  int mid = (n-1);  //use multiply by 2 instead of dividing, as it creates problems for even 'n'
  int **d = allocate2D(n,n);

  for(int i=0; i<n; i++) for(int j=0; j<n; j++){
    int i_new = (((2*j-mid)*1) + mid)/2;
    int j_new = ((-1*(2*i-mid)) + mid)/2;

    d[i_new][j_new] = a[i][j];
  }
  return d;
}

int main() {
  int n = 5;
  int **a = allocate2D(n,n);
  
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) a[i][j] = i*n+j;

  cout<<"Input Matrix: \n";  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ 
      cout<<a[i][j]<<" "; 
    }
    cout<<endl;
  }

  int **d = rotate(a,n);

  cout<<"Rotated Matrix: \n";  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ 
      cout<<d[i][j]<<" "; 
    }
    cout<<endl;
  }

  return 0;
}
