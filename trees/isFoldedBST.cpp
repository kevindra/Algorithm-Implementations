/**
  * File Name : bst_basic.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Thursday 19 May 2011 04:38:19 PM IST
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

bool isFolded(node *root1, node *root2){
  if(root1 == NULL && root2 == NULL) return true;
  if(root1 == NULL && root2 != NULL) return false;
  if(root1 != NULL && root2 == NULL) return false;
  return isFolded(root1->left, root2->right) && isFolded(root1->right, root2->left);
}

int main() {
  int a[] = {10, 7, 5, 11, 15}, n = 5;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  cout<<"Folded: "<<isFolded(root, root)<<endl;
  return 0;
}
