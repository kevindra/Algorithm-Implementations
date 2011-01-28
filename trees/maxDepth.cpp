/**
  * File Name : bst_basic.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 03:26:53 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  node *left, *right;
};

node *root;

node *newnode( int n ) {
  node *np = new node;
  np->n = n;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert ( node *&rt, node *np ) {
  if( rt == NULL ) rt = np;
  else if( np->n >= rt->n ) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder( node *rt ) {
  if(rt != NULL) {
    inorder(rt->left);
    cout<<rt->n<<" -> ";
    inorder(rt->right);
  }
}

int maxDepth( node *rt )  {
  if(rt == NULL) return 0; 
  return max ( maxDepth(rt->left), maxDepth(rt->right) ) + 1;
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

  cout<<"Max Depth: "<<maxDepth(root)<<endl;
  return 0;
}
