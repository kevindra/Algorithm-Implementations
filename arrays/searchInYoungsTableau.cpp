/**
  * File Name : searchInYoungsTableau.cpp
  *
  * Purpose :
  * Creation Date : 01-02-2011
  *
  * Last Modified : Tuesday 01 February 2011 03:24:28 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int **allocate2D(int **m, int r, int c) {
  m = (int**) malloc(sizeof(int)*r*c);
  for(int i=0; i<r; i++)  m[i] = (int*) malloc(sizeof(int)*c);
  return m;
}

int **createYoungsTableau( int n )  {
  int **m;
  m = allocate2D(m, n, n);
  int c = 1;
  for(int i=0; i<n; i++)  for(int j=0; j<n; j++) m[i][j] = c++;
  return m;
}

void print(int **m, int r, int c) {
  for(int i=0; i<r; i++)  {
    for(int j=0; j<c; j++)
      cout<<m[i][j]<<" ";
    cout<<endl;
  }
}

bool searchInYT(int **m, int n, int key, int &pi, int &pj) {
  int midi, midj;
  int i = n-1, j = 0;
  
  while( i >= 0 && i < n && j >= 0 && j < n )  {
    if(m[i][j] == key)  {
      pi = i, pj = j;
      return true;
    }
    else if( m[i][j] < key )  j++;
    else i--;
  }
  return false;
}

struct pos{
  int i,j;
};

/** Using Divide and Conquer **/
/** Binary Search Partition Solution **/
pos *searchInYT2(int **m, int n, int key, int start, int end)  {
  if(start > end) return NULL;

  int mid = (start + end)/2;
  int mi = mid/n;
  int mj = mid%n;

  pos *p = new pos;

  if( m[mi][mj] == key )  {
    p->i = mi, p->j = mj;
    return p;
  }
  else if( key < m[mi][mj] )  {
    return searchInYT2(m, n, key, start, mid);
  }
  else {
    return searchInYT2(m, n, key, mid+1, end);
  }
}

int main()  { 
  int n = 5;
  int **yt = createYoungsTableau(n);
  print(yt, n, n);


  for(int toFind = 1; toFind <= n*n; toFind++)  {
    cout<<"To Find: "<<toFind<<" -> \n";
    int fi,fj;
    bool found = searchInYT(yt, n, toFind, fi, fj);
    
    cout<<"Simple Method: "<<endl;
    if(found) cout<<"Found at: "<<fi<<" "<<fj<<endl;
    else cout<<"Not found\n";
  
    pos *p = searchInYT2(yt, n, toFind, 0, n*n-1);
  
    cout<<"\nDivide and Conquer Method: \n";
    if(p) cout<<"Found at: "<<p->i<<" "<<p->j<<endl;
    else cout<<"Not found\n";
  }
  return 0;
}
