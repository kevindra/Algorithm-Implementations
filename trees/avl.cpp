/**
  * File Name : avl.cpp
  *
  * Purpose :
  * Creation Date : 09-02-2011
  *
  * Last Modified : Wednesday 09 February 2011 06:45:51 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

/**
  * specifications:
  *
  */

// Based on this reference: http://www.docstoc.com/docs/27383959/AVL-tree-in-C

#include <iostream>
#include <math.h>

using namespace std;

struct node {
  int n, h;
  node *left, *right, *parent;
};
node *root = NULL;

node *newnode( int n )  {
  node *np  = new node;
  np->n = n;
  np->h = 0;
  np->left  = np->right = np->parent = NULL;
  return np;
}

int height(node *rt)  {
  if(rt == NULL) return 0;
  return max( height(rt->left), height(rt->right) ) + 1;
}

void rotateWithLeftChild( node *&k2 )  {
  node *k1  = k2->left;
  k2->left  = k1->right;
  k1->right = k2;
  k2->h     = max( height(k2->left), height(k2->right) ) + 1;
  k1->h     = max( height(k1->left), k2->h ) + 1;
  k2 = k1;
}

void rotateWithRightChild( node *&k1 ) {
  node *k2  = k1->right;
  k1->right = k2->right;
  k2->left  = k1;
  k1->h     = max( height(k1->left), height(k1->right) ) + 1;
  k2->h     = max( height(k2->right), k1->h ) + 1;
  k1  = k2;
}

void doubleWithLeftChild( node *&k3 ) {
  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}

void doubleWithRightChild( node *&k1 )  {
  rotateWithLeftChild(k1->right);
  rotateWithRightChild(k1);
}

void insert(node *&t, int x) {
  cout<<"Inserting: "<<x<<endl;
  if(t==NULL) {
    t = newnode(x);
  }
  else if(x < t->n) {
    insert(t->left, x);
    if( (height(t->left) - height(t->right)) == 2 )  {
      if( x < t->left->n )  rotateWithRightChild(t);
      else  doubleWithLeftChild(t);
    }
  }
  else if(x > t->n) {
    insert(t->right, x);
    if( (height(t->right)  - height(t->left)) == 2 ) {
      if( x < t->left->n ) rotateWithRightChild(t);
      else doubleWithLeftChild(t);
    }
  }
}

void inorder( node *rt )  {
  if(rt==NULL) return;
  inorder(rt->left);
  cout<<rt->n<<" ";
  inorder(rt->right);
}

int main()  {
  int a[] = {1,2,3,4,5,6,7,8,9,10}, n = 10;
  for(int i =0; i<n; i++) insert(root, a[i]);

  cout<<"Tree: "<<endl;
  inorder(root);

  cout<<"Height: "<<height(root)<<endl;
  return 0;
}
