/**
  * File Name : bfsMatrix.cpp
  *
  * Purpose :
  * Creation Date : 03-02-2011
  *
  * Last Modified : Thursday 03 February 2011 03:51:36 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string.h>

using namespace std;

int **allocate2D(int r, int c)  {
  int **m = (int**) malloc(sizeof(int)*r*c);
  for(int i=0; i<r; i++) m[i] = (int*)malloc(sizeof(int)*c);
  return m;
}

int **initGraph(int n)  {
  int **g = allocate2D(n, n);
  for(int i=0; i<n; i++) for(int j=0; j<n; j++)
    if(i == j) g[i][j]  = 0;
    else g[i][j] = -1;
  return g;
}

void addEdge(int **g, int i, int j) {
  g[i][j] = g[j][i] = 1;
}

void displayGraph(int **g, int n) {
  for(int i=0; i<n; i++)  {
    for(int j=0; j<n; j++)  cout<<g[i][j]<<" ";
    cout<<endl;
  }
}

int *visited;
void bfs(int **g, int n ) {
  list<int> q;

  visited[0] = 1;
  q.push_back(0);

  while(q.size()) {
    int p = q.front();
    q.pop_front();

    cout<<p<<" ";

    for(int i=0; i<n; i++) 
      if(g[p][i] == 1 && !visited[i] ) q.push_back(i), visited[i] = 1;
  }
}

int main()  {
  int n = 5;
  int **g = initGraph(5);

  int e = 8;
  for(int i=0; i<e; i++)  {
    int a = rand()%n;
    int b = rand()%n;
    if(a == b) continue;
    addEdge(g, a, b);
  }

  cout<<"Graph: \n";
  displayGraph(g, n);


  visited = new int[n];
  memset(visited, 0, sizeof(int)*n);

  cout<<"DFS : ";
  bfs(g, n);
  cout<<endl;

  return 0;
}
