/**
  * File Name : nthInorderNode.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 06:03:59 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  node *left, *right;
};
node *root = NULL;

node *newnode (int n) {
  node *np = new node;
  np->n   = n;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert( node *&rt, node *np )  {
  if(rt == NULL) rt = np;
  else if(np->n >= rt->n) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder( node *rt )  {
  if(rt == NULL) return;
  inorder(rt->left);
  cout<<rt->n<<" -> ";
  inorder(rt->right);
}

void nthNode( node *rt, int &n, node *&found ) {
  if(rt == NULL) return;

  nthNode(rt->left, n, found);
  if(n == 1) found = rt;
  n-=1;
  nthNode(rt->right, n, found);
}

int main() {
  int a[] = {5,2,4,7,8,2,4,67,9,2,3,56}, n = 12;
  //int a[] = {5,4,8,6,5,9,2}, n = 7;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;
  
  int p = 11;

  node *found = NULL;
  nthNode(root, p, found);

  if(found) cout<<"Found node is: "<<found->n<<endl;
  else cout<<"Not found"<<endl;

  return 0;
}
