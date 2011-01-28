/**
  * File Name : noOfLeaves.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Saturday 29 January 2011 12:09:42 AM IST
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

int leaves = 0;
void noOfLeaves( node *rt )  {
  if(rt == NULL) return;

  noOfLeaves(rt->left);
  if(rt->left == NULL && rt->right == NULL) leaves++;
  noOfLeaves(rt->right);
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

  noOfLeaves(root);
  cout<<"No. of leaves: "<<leaves<<endl;
  return 0;
}

