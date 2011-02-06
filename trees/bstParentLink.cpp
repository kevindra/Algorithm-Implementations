/**
  * File Name : bstParentLink.cpp
  *
  * Purpose :
  * Creation Date : 05-02-2011
  *
  * Last Modified : Sunday 06 February 2011 02:10:52 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  node *left, *right, *parent;
};
node *root = NULL;

node *newnode (int n) {
  node *np  = new node;
  np->n = n;
  np->left  = NULL;
  np->right = NULL;
  np->parent  = NULL;
  return  np;
}

void insert(node *&rt, node *np)  {
  if(rt == NULL)  { rt  = np; return; }

  if(np->n < rt->n) {
    if(rt->left == NULL) {  rt->left = np; np->parent = rt; }
    else insert(rt->left, np);
  }
  else  {
    if(rt->right  ==  NULL) { rt->right = np; np->parent  = rt; }
    else  insert(rt->right, np);
  }
}

void inorder( node *rt )  {
  if(rt == NULL) return;
  inorder(rt->left);
  if(rt->parent)
    cout<<"Node: "<<rt->n<<", Parent: "<<rt->parent->n<<endl;
  else
    cout<<"Node: "<<rt->n<<", Parent: NONE"<<endl;
  inorder(rt->right);
}

int main()  {
  int a[] = {8,4,5,7,1,2,8,3,5,10}, n=10;
  
  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  inorder(root);
  return 0;
}
