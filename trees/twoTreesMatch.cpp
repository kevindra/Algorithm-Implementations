/**
  * File Name : twoTreesMatch.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 03:12:17 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
  int n;
  node *left, *right;
};
node *root1 = NULL;
node *root2 = NULL;

node *newnode ( int n ) {
  node *np  = new node;
  np->n = n;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert (node *&rt, node *np) {
  if(rt == NULL) rt = np;
  else if(np->n >= rt->n) insert (rt->right, np);
  else insert (rt->left, np);
}

void inorder ( node *rt ) {
  if(rt != NULL)  {
    inorder(rt->left);
    cout<<rt->n<<" -> ";
    inorder(rt->right);
  }
}

bool areIdentical( node *r1, node *r2 ) {
  if(r1 == NULL && r2 == NULL) return true;
 
  if(r1 != NULL && r2 != NULL)  {
    return (r1->n == r2->n) 
            && areIdentical(r1->left, r2->left) 
            && areIdentical(r1->right, r2->right);
  } 
  else return false;
}

int main() {
  int a[] = {6,4,56,6,2,3,5,67,7,2}, n1=10;
  int b[] = {4,56,6,2,3,5,67,7,2}, n2=9;
  
  for(int i=0; i<n1; i++) insert(root1, newnode(a[i]) );
  for(int i=0; i<n2; i++) insert(root2, newnode(b[i]) );

  cout<<"first: "; inorder(root1);
  cout<<endl;
  cout<<"second: "; inorder(root2);
  cout<<endl;

  cout<<"Are identical: "<< areIdentical(root1, root2)<<endl;
  return 0;
}
