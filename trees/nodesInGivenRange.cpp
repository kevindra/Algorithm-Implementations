/**
  * File Name : bst_basic.cpp
  *
  * Purpose : Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Print all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Print all the keys in increasing order.
  *
  * Creation Date : 28-01-2011
  *
  * Last Modified : Thursday 19 May 2011 11:25:33 AM IST
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

void printKeysInRange( node *rt , int k1, int k2) {
  if(rt != NULL) {
    if(rt->n > k1)  printKeysInRange(rt->left, k1, k2);
    if(rt->n >= k1 && rt->n <= k2) cout<<rt->n<<" -> ";
    if(rt->n <= k2) printKeysInRange(rt->right, k1, k2);
  }
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

  cout<<"Inorder : \n";
  printKeysInRange(root, 2, 20);
  cout<<endl;

  return 0;
}
