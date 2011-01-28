/**
  * File Name : isMirror.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 05:14:19 PM IST
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
node *mroot = NULL;

node *newnode( int n ) {
  node *np = new node;
  np->n = n;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert ( node *&rt, node *np ) {
  if(rt == NULL) rt = np;
  else if(np->n >= rt->n) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder ( node *rt ) {
  if( rt == NULL ) return;

  inorder(rt->left);
  cout<<rt->n<<" -> ";
  inorder(rt->right);
}

node *createMirror( node *rt ) {
  if(rt == NULL) return NULL;

  node *np = new node;
  np->n = rt->n;
  np->left  = createMirror(rt->right);
  np->right = createMirror(rt->left);
  return np;
}


bool isMirror( node *rt1, node *rt2 ) {
  if( rt1 == NULL && rt2 == NULL ) return true;
  
  if( rt1 != NULL && rt2 != NULL )  {
    return (rt1->n == rt2->n)
            && isMirror(rt1->left, rt2->right) 
            && isMirror(rt1->right, rt2->left);
  }
  else return false;
}

int main()  {
  int a[] = {5,2,4,7,8,2,4,67,9,2,3,56}, n = 12;
  //int a[] = {5,4,8,6,5,9,2}, n = 7;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  mroot = createMirror(root);
  
  cout<<"Mirror's Inorder : \n";
  inorder(mroot);
  cout<<endl;
  
  cout<<"Are Mirror to each other: "<<((isMirror(root, mroot))?" Yes":" No")<<endl;
  return 0;
}
