/**
  * File Name : searchNode.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 11:21:38 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  node *left, *right;
};
node *root  = NULL;

node *newnode(int n)  {
  node *np = new node;
  np->n = n;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert(node *&rt, node *np)  {
  if(rt == NULL) rt = np;
  else if(np->n >= rt->n) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder(node *rt)  {
  if(rt == NULL) return;
  inorder(rt->left);
  cout<<rt->n<<" -> ";
  inorder(rt->right);
}

node *find(node *rt, int val) {
  if(rt==NULL) return NULL;
  if(val > rt->n) return find(rt->right,val);
  else if(val < rt->n) return find(rt->left,val);
  else return rt;
}

int main(){
  int a[] = {5,2,4,7,8,2,4,67,9,2,3,100}, n = 12;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  node *found = find(root, 100);

  if(found == NULL) cout<<"Not found\n";
  else cout<<"Found: "<<found->n<<endl;
  return 0;
}
