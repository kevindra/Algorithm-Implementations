/**
  * File Name : bstSuccessor.cpp
  *
  * Purpose :
  * Creation Date : 07-02-2011
  *
  * Last Modified : Monday 07 February 2011 11:17:15 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  node *parent, *left, *right;
};
node *root  = NULL;

node *newnode( int n )  {
  node *np  = new node;
  np->n = n;
  np->left  = np->right = np->parent  = NULL;
  return np;
}

void insert( node *&rt, node *np  ) {
  if(rt ==  NULL) rt  = np;
  else if(np->n < rt->n)  {
    if(rt->left ==  NULL) { rt->left  = np; np->parent  = rt; }
    else  insert(rt->left, np);
  }
  else {
    if(rt->right  ==  NULL) { rt->right = np; np->parent  = rt; }
    else insert(rt->right, np);
  }
}

/**
  * To find Successor, we have two steps:
  *
  * If Node X has Right Subtree:
  * Step 1: Find the minimum value node in right subtree.
  *
  * If Node X does not have Right Subtree:
  * Step 2: Find the ancestor whose left subtree contains X.
  *
  */

/** Returns TreeMinimum, Root: rt **/
node *treeMin( node *rt ){
  if(rt->left == NULL)  return rt;
  return treeMin(rt->left);
}

node *successor(node *rt) {
  if(rt->right != NULL) return treeMin(rt->right);
  else  {
    while(rt->parent) {
      if(rt->parent->left == rt) return rt->parent;
      rt  = rt->parent;
    }
    return NULL;
  }
}

void inorder( node *rt )  {
  if(rt ==  NULL) return;
  inorder(rt->left);
  if(rt->parent)
    cout<<"Node: "<<rt->n<<", Parent: "<<rt->parent->n;
  else
    cout<<"Node: "<<rt->n<<", Parent: NULL";
  
  node *sux = successor(rt);
  if(sux) cout<<" Successor: "<<sux->n<<endl;
  else cout<<" Successor: NULL"<<endl;

  inorder(rt->right);
}


int main()  {
  int a[] = {8,4,5,7,1,2,8,3,5,10}, n=10;
  
  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  inorder(root);
  return 0;
}
