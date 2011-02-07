/**
  * File Name : bstPredecessor.cpp
  *
  * Purpose :
  * Creation Date : 07-02-2011
  *
  * Last Modified : Monday 07 February 2011 11:39:10 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node{
  int n;
  node *left, *right, *parent;
};
node *root  = NULL;

node *newnode(int n){
  node *np  = new node;
  np->n = n;
  np->left  = np->right = np->parent  = NULL;
  return np;
}

void insert(node *&rt, node *np)  {
  if(rt ==  NULL) rt  = np;
  else if(np->n < rt->n)  {
    if(rt->left ==  NULL) { rt->left  = np; np->parent  = rt; }
    else insert(rt->left, np);
  }
  else {
    if(rt->right  ==  NULL) { rt->right = np; np->parent  = rt; }
    else  insert(rt->right, np);
  }
}

node *getMax(node *rt)  {
  if(rt->right == NULL) return rt;
  return getMax(rt->right);
}

node *predecessor(node *rt) {
  if(rt->left)  return getMax(rt->left);
  else  {
    while(rt->parent) {
      if(rt->parent->right  ==  rt) return rt->parent;
      rt  = rt->parent;
    }
    return NULL;
  }
}

void inorder(node *rt)  {
  if(rt ==  NULL) return;
  inorder(rt->left);

  if(rt->parent)
    cout<<"Node: "<<rt->n<<", Parent: "<<rt->parent->n<<" Predecessor: ";
  else
    cout<<"Node: "<<rt->n<<", Parent: NULL, Predecessor: ";

  node *pre = predecessor(rt);

  if(pre) cout<<pre->n<<endl;
  else cout<<" NULL"<<endl;

  inorder(rt->right);
}

int main(){
  int a[] = {8,4,5,7,1,2,8,3,5,10}, n=10;
  
  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  inorder(root);
  return 0;
}
