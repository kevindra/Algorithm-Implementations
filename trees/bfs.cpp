/**
  * File Name : levelOrderTraversal.cpp
  *
  * Purpose :
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 07:31:24 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <list>

using namespace std;

struct node {
  int n;
  node *left, *right;
};
node *root = NULL;

node *newnode( int n )  {
  node *np  = new node;
  np->n = n;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert( node *&rt, node *np  ) {
  if(rt ==  NULL) rt  = np;
  else if( np->n >= rt->n ) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder(node *rt)  {
  if(rt==NULL) return;
  inorder(rt->left);
  cout<<rt->n<<" -> ";
  inorder(rt->right);
}

void levelOrder( node *root ) {
  list<node*> q;
  q.push_back(root);

  while(q.size()) {
    node *n = q.front();

    if(n->left) q.push_back(n->left);
    if(n->right) q.push_back(n->right);
    q.pop_front();
    cout<<n->n<<" -> ";
  }
}

int main()  {
  int a[] = {1,2,3,5,6,7,8}, n = 7;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  cout<<"level order: \n";
  levelOrder(root);
  cout<<endl;

  return 0;
}
