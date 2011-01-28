/**
  * File Name : multiplyTwoMatrix.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 05:31:51 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int **allocate2D( int **mat, int m, int n )  {
  mat = (int**) malloc( sizeof(int)*m*n );
  for( int i=0; i<m; i++) mat[i] = (int*) malloc( sizeof(int)*n );
  return mat;
}

int **multiply (int **m1, int **m2, int m, int n, int k) {
  int **res;
  res = allocate2D(res, m, k);
  
  for(int a=0; a<m; a++)  for(int b=0; b<k; b++)  {
    res[a][b] = 0;
    for(int c=0; c<n; c++) res[a][b] += m1[a][c]*m2[c][b];
  }
  return res;
}

void printMat( int **mat, int a, int b ) {
  for( int i=0; i<a; i++ )  {
    for( int j=0; j<b; j++ )  cout<<mat[i][j]<<" ";
    cout<<endl;
  }
}

int main() {
  int **a,**b;
  int m,n,k;
  m = 2, n = 2, k = 3;
 
  /** for matrices to multiply one dimensional size should be same **/

  a = allocate2D(a,m,n);
  b = allocate2D(b,n,k); 
  
  int cnt = 0; 
  for(int i=0; i<m; i++) for(int j=0; j<n; j++) a[i][j] = cnt++;

  cnt = 0;
  for(int i=0; i<n; i++) for(int j=0; j<k; j++) b[i][j] = cnt++;
  

  cout<<"\nMatrix 1: \n";
  printMat(a, m, n);

  cout<<"\nMatrix 2: \n";
  printMat(b, n, k);
  
  int **res = multiply ( a, b, m, n, k );
  cout<<"\nMutiplication: \n";
  printMat(res, m, k);
  cout<<endl;

  return 0;
}
