/**
  * File Name : bst_basic.cpp
  *
  * Purpose : Write a program that converts a given tree to its Double tree. To create Double tree of the given tree, create a new duplicate for each node, and insert the duplicate as the left child of the original node.
  *
  * Creation Date : 28-01-2011
  *
  * Last Modified : Thursday 19 May 2011 05:20:55 PM IST
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

void convertToDoubleTree(node *root){
  if(root == NULL) return;
  
  if(root->left == NULL) root->left = newnode(root->n);
  else {
    node *np = newnode(root->n);
    np->left = root->left;
    root->left = np;
  }

  convertToDoubleTree(root->left->left);
  convertToDoubleTree(root->right);
}

int main() {
  int a[] = {2, 1, 3}, n = 3;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  convertToDoubleTree(root);
  
  cout<<"Double Tree: \n";
  inorder(root);
  cout<<endl;
  return 0;
}
