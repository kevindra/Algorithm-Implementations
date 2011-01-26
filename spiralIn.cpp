/**
  * File Name : spiralIn.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 03:19:31 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>
#include <stdlib.h>

using namespace std;

void print( int **mat, int r, int c )  {
  for(int i=0; i<r; i++)  {
    for(int j=0; j<c; j++)  {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}

void spiral( int **m, int r, int c )  {
  int dj[] = {1,0,-1,0};
  int di[] = {0,1,0,-1};
  bool **flag = (bool**) malloc(sizeof(bool**)*r*c);
  for(int i=0;i<r;i++) flag[i] = (bool*)malloc(sizeof(bool*)*c);

  /** mark all as unvisited **/
  for(int i=0;i<r;i++) for(int j=0;j<c;j++) flag[i][j] = false;

  int n = r*c, dir=0;
  
  int i=0,j=0;
  while(n)  {
    if( i >= r || i < 0 || j >= c || j < 0 || flag[i][j] ){ 
      i -= di[dir], j -= dj[dir];
      dir = (dir+1)%4; 
    }
    else  {
      n--;
      cout<<m[i][j]<<"->";
    }
    flag[i][j] = true;
    i += di[dir];
    j += dj[dir];
  }
}

int main (){
  int **mat, cnt=1;
  int r=5,c=5;
  mat = (int **)malloc(sizeof(int**)*r);
  for(int i=0;i<r;i++)  mat[i] = (int*) malloc(sizeof(int)*c);

  for(int i=0; i<r; i++) for(int j=0; j<c; j++) mat[i][j] = cnt++;
 
  cout<<"Input Matrix: \n"; 
  print(mat,r,c);
  
  cout<<"\nSpiral: ";
  spiral(mat,r,c);
  return 0;
}
