/**
  * File Name : lowestCommonAncestor2.cpp
  *
  * Purpose :
  * Creation Date : 06-02-2011
  *
  * Last Modified : Sunday 06 February 2011 02:43:23 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node{
  int n, level;
  node *left, *right, *parent;
};
node *root  = NULL;

node *newnode(int n)  {
  node *np  = new node;
  np->n = n;
  np->level = 0;
  np->left  = NULL;
  np->right = NULL;
  np->parent  = NULL;
  return np;
}

void insert(node *&rt, node *np, int level){
  if(rt ==  NULL) { rt  = np; return; }

  if(np->n < rt->n) {
    if(rt->left ==  NULL) { rt->left  = np; np->parent = rt; np->level = level+1;  }
    else insert(rt->left, np, level+1);
  }
  else  {
    if(rt->right  ==  NULL) { rt->right = np; np->parent = rt; np->level = level+1;  }
    else  insert(rt->right, np, level+1);
  }
}

void inorder( node *rt )  {
  if(rt ==  NULL) return;
  inorder(rt->left);
  if(rt->parent)
    cout<<"Node: "<<rt->n<<", Parent: "<<rt->parent->n<<", Level: "<<rt->level<<endl;
  else
    cout<<"Node: "<<rt->n<<", Parent: NULL, Level: "<<rt->level<<endl;
  inorder(rt->right);
}

node *LCA(node *a, node *b){
  while(a != b){
    if(a->level < b->level) b = b->parent;
    else if(a->level > b->level) a = a->parent;
    else a = a->parent, b = b->parent;
  }
  return a;
}

int main(){
  int a[] = {8,4,5,7,1,2,8,3,5,10}, n=10;
  
  for(int i=0; i<n; i++) insert(root, newnode(a[i]), 0);

  inorder(root);

  node *A = root->left->left->right->right;
  node *B = root->right->right;
  node *lca = LCA(A,B);

  cout<<"LCA of "<<A->n<<" and "<<B->n<<": "<<lca->n<<endl;
  return 0;
}
