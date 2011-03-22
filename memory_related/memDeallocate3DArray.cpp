/**
  * File Name : memDeallocate3DArray.cpp
  *
  * Purpose :
  * Creation Date : 22-03-2011
  *
  * Last Modified : Tuesday 22 March 2011 12:57:20 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <cstdlib>

using namespace std;

int ***allocate3D(int ***mat, int k, int l, int m){
  mat = (int***)malloc( sizeof(int)*k*l*m );

  for(int i=0; i<k; i++)  
    mat[i] = (int**)malloc (sizeof(int)*l*m);

  for(int i=0; i<k; i++) for(int j=0; j<l; j++)
    mat[i][j] = (int*) malloc(sizeof(int)*m);

  return mat;
}


void deAllocate3D(int ***mat, int k, int l, int m){
  for(int i=0; i<k; i++) for(int j=0; j<l; j++) { free(mat[i][j]); mat[i][j] = NULL; }
  
  for(int i=0; i<k; i++) { free(mat[i]); mat[i] = NULL; }
  
  free(mat); mat = NULL;
}

int main(){
  int ***mat;
  int k=2,l=3,m=4;
  mat = allocate3D(mat, k,l,m);
  
  int cnt = 0;
  for(int i=0;i<k;i++) for(int j=0;j<l;j++) for(int q=0;q<m;q++) mat[i][j][q] = cnt++;
  
  for(int i=0; i<k; i++){
    cout<<"I: "<<i<<endl;
    for(int j=0; j<l; j++){
      for(int q=0; q<m; q++){
        cout<<mat[i][j][q]<<" ";
      }
      cout<<endl;
    }
  }

  deAllocate3D(mat, k, l, m);

  return 0;
}
