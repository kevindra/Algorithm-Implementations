/**
  * File Name : isBST.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 07:20:38 PM IST
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

node *newnode( int n )  {
  node *np  = new node;
  np->n = n;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert( node *&rt,  node *np ) {
  if(rt ==  NULL) rt  = np;
  else if( np->n >= rt->n ) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder( node *rt )  {
  if(rt ==  NULL) return;
  inorder(rt->left);
  cout<<rt->n<<" -> ";
  inorder(rt->right);
}

bool isBST(node *rt)  {
  if(rt == NULL)  return true;

  if(rt->left != NULL)  {
    if(rt->n > rt->left->n) return true && isBST(rt->left);
    else return false && isBST(rt->left);
  }
  else if(rt->right != NULL) {
    if(rt->n <= rt->right->n) return true && isBST(rt->right);
    else return false && isBST(rt->right);
  }
  else return true;
}

int main(){
  int a[] = {5,2,4,7,8,2,4,67,9,2,3,56}, n = 12;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));
  
  //root->left->n = 10; //just to make the tree non-BST

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  cout<<"Is BST: "<<((isBST(root))?" Yes":" No")<<endl;
  return 0;
}
