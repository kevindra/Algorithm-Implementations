/**
  * File Name : bst_basic.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Thursday 19 May 2011 05:07:45 PM IST
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

int height(node *root){
  if(root == NULL) return 0;
  return max(height(root->left), height(root->right)) + 1;
}

int getWidth(node *root, int i){
  if(root == NULL) return 0;
  if(i==0) return 1;
  return getWidth(root->left, i-1) + getWidth(root->right, i-1);
}

int getMaxWidth(node *root){
  int h = height(root);
  cout<<"Height: "<<h<<endl;


  int mxWidth = 0;
  for(int l=0; l<h; l++){
    cout<<"Width at Level "<<l<<": "<<getWidth(root, l)<<endl;
    mxWidth = max( getWidth(root, l), mxWidth );
  }
  return mxWidth;
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

  cout<<"\nMax Width of BST: "<<getMaxWidth(root)<<endl;
  return 0;
}
