/**
  * File Name : bst_basic.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Thursday 19 May 2011 05:47:56 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string>
#include <sstream>

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
void printAllPaths(node *root, string s){
  if(root == NULL) return;
  stringstream ss;
  ss << root->n;

  if(root->left == NULL && root->right == NULL) {
    cout<<s<<ss.str()<<endl;
  }

  printAllPaths(root->left, s + ss.str() + " -> ");
  printAllPaths(root->right, s + ss.str() + " -> ");
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

  cout<<"Paths: \n";
  printAllPaths(root, "");
  return 0;
}
