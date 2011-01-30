/**
  * File Name : dfs.cpp
  *
  * Purpose :
  * Creation Date : 30-01-2011
  *
  * Last Modified : Sunday 30 January 2011 10:24:00 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  int visited;
  node *left, *right;
};

node *root  = NULL;

node *newnode( int n )  {
  node *np = new node;
  np->n = n;
  np->visited = 0;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert( node *&rt, node *np ) {
  if(rt == NULL) rt = np;
  else if( np->n >= rt->n ) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder( node *rt ) {
  if(rt == NULL) return;
  inorder(rt->left);
  cout<<rt->n<<" -> ";
  inorder(rt->right);
}

void dfs( node *rt ) {
  if(rt == NULL) return;
  if(rt->visited == 1) return;

  cout<<rt->n<<" -> ";
  rt->visited = 1;
  /** visit all connected nodes to 'rt' **/
  dfs(rt->left);
  dfs(rt->right);
}

int main() {
  int a[] = {5,2,4,7,8,2,4,67,9,2,3,56}, n = 12;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  cout<<"DFS: \n";
  dfs(root);
  cout<<endl;

  return 0;
}
