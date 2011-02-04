/**
  * File Name : bfsDirectedMatrix.cpp
  *
  * Purpose :
  * Creation Date : 03-02-2011
  *
  * Last Modified : Thursday 03 February 2011 05:01:36 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int **allocate2D(int r, int c)  {
  int **m = (int**) malloc( sizeof(int)*r*c);
  for(int i=0; i<r; i++)  m[i]  = (int*) malloc(sizeof(int)*c);
  return  m;
}

int **initGraph(int n)  {
  int **g = allocate2D(n, n);
  for(int i=0; i<n; i++) for(int j=0; j<n; j++)
    if(i==j) g[i][j]  = 0;
    else g[i][j] = -1;
  return g;
}

void addEdge(int **g, int i, int j) {
  g[i][j] = 1;
}

void displayGraph(int **g, int n) {
  for(int i=0; i<n; i++)  {
    for(int j=0; j<n; j++) 
      cout<<g[i][j]<<" ";
    cout<<endl;
  }
}

void bfs(int **g)  {
}

int main(){
  int n = 5;
  int **g = initGraph(5);

  int e = 8;
  for(int i=0; i<e; i++)  {
    int a = rand()%n;
    int b = rand()%n;
    addEdge(g, a, b);
  }

  cout<<"Graph: \n";
  displayGraph(g, n);

  return 0;
}
