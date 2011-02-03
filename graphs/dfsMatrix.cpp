/**
  * File Name : dfsMatrix.cpp
  *
  * Purpose :
  * Creation Date : 03-02-2011
  *
  * Last Modified : Thursday 03 February 2011 02:43:00 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int **allocate2D( int r, int c )  {
  int **m;
  m = (int**)malloc(sizeof(int)*r*c);
  for(int i=0; i<r; i++) m[i] = (int*)malloc(sizeof(int)*c);
  return m;
}

int **initGraph( int n )  {
  int **g = allocate2D(n, n);
  
  for(int i=0; i<n; i++)  for(int j=0; j<n; j++)
    if( i == j ) g[i][j] = 0;
    else g[i][j] = -1;

  return g;
}

void addEdge( int **g, int i, int j ) {
  g[i][j] = g[j][i] = 1;
} 
void addEdge( int **g, int i, int j, int cost ) {
  g[i][j] = g[j][i] = cost;
}

void displayGraph ( int **g, int n )  {
  for(int i=0; i<n; i++)  {
    for(int j=0; j<n; j++)
      cout<<g[i][j]<<" ";
    cout<<endl;
  }
}

int *visited;
void dfs(int **g, int n, int i)  {
  if( visited[i] == 1 ) return;
  
  visited[i] = 1;
  cout<<i<<" ";

  // iterate through all its neighbours
  for(int p=0; p<n; p++)  if(!visited[p])
    dfs(g, n, p);
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


  visited = new int[n];
  memset(visited, 0, sizeof(int)*n);

  cout<<"DFS : ";
  dfs(g, n, 0);
  cout<<endl;

  return 0;
}
