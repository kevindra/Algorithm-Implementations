/**
  * File Name : 3DmatrixAllocation.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 04:45:48 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>
#include <stdlib.h>

using namespace std;

int ***allocate3D(int ***mat, int k, int l, int m)  {
  mat = (int***) malloc( sizeof(int)*k*l*m );

  for(int i=0;i<k;i++)
    mat[i] = (int**) malloc ( sizeof(int)*l*m );

  for(int i=0; i<k; i++)  for(int j=0; j<l; j++) 
    mat[i][j] = (int*) malloc ( sizeof(int)*m );

  return mat;
}

int main () {
  int ***mat;
  int k,l,m;
  k = 5, l = 5, m = 5;

  mat = allocate3D( mat, k, l, m);

  int cnt = 0;
  for(int p=0; p<k; p++) {
    for(int q=0; q<l; q++) {
      for(int r=0; r<m; r++)  {
        mat[p][q][r] = cnt++;
      }
    }
  }
  cout<<"Matrix: \n";

  for(int p=0; p<k; p++) {
    cout<<"Level "<<p<<": \n";
    for(int q=0; q<l; q++) {
      for(int r=0; r<m; r++)  {
        cout<<mat[p][q][r]<<" ";
      }
      cout<<endl;
    }
  }

  return 0;
}
