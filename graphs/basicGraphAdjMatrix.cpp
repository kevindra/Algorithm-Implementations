/**
  * File Name : basicGraphAdjMatrix.cpp
  *
  * Purpose :
  * Creation Date : 02-02-2011
  *
  * Last Modified : Thursday 03 February 2011 11:23:06 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

int **allocate2D(int r, int c)  {
  int **m;
  m = (int**)malloc(sizeof(int)*r*c);
  for(int i=0; i<r; i++)  m[i]  = (int*)malloc(sizeof(int)*c);
  return m;
}

int **initGraph(int n) {
  int **g = allocate2D(n, n);
  for(int i=0; i<n; i++) for(int j=0; j<n; j++)
    if(i==j)  g[i][j] = 0;
    else g[i][j] = -1;
  return g;
}

/**
  * AddEdge - Cost 1 for all kind of edges
  */
void addEdge(int **g, int i, int j) {
  g[i][j] = g[j][i] = 1;
}

/**
  * AddEdge - Cost is user defined
  */
void addEdge(int **g, int i, int j, int cost) {
  g[i][j] = g[j][i] = cost;
}

/**
  * To display Graph Matrix
  */
void displayGraph(int **g, int n) {
  for(int i=0; i<n; i++) {  
    for(int j=0; j<n; j++)
      cout<<g[i][j]<<" ";
    cout<<endl;
  }
}

int main()  {
  int n = 5;
  int **g = initGraph(5);

  int e = 8;
  for(int i=0; i<e; i++)  {
    int a = rand()%n;
    int b = rand()%n;
    addEdge(g, a, b, 1);
  }

  cout<<"Graph: \n";
  displayGraph(g, n);

  return 0;
}
