/**
  * File Name : bst_basic.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Thursday 19 May 2011 04:25:50 PM IST
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

void kDistanceFromRoot(node *root, int k){
  if(root == NULL) return;
  if(k==0) cout<<root->n<<", ";
  kDistanceFromRoot(root->left, k-1);
  kDistanceFromRoot(root->right, k-1);
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

  for(int i=0; i<=5; i++){
    cout<<"Nodes at distance "<<i<<" from root: ";
    kDistanceFromRoot(root, i);
    cout<<endl;
  }
  return 0;
}
