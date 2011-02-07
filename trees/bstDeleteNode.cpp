/**
  * File Name : bstDeleteNode.cpp
  *
  * Purpose :
  * Creation Date : 07-02-2011
  *
  * Last Modified : Tuesday 08 February 2011 01:16:23 AM IST
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

node *newnode( int n )  {
  node *np  = new node;
  np->n = n;
  np->left  = np->right = np->parent  = NULL;
  return np;
}

void insert ( node *&rt, node *np ) {
  if(rt ==  NULL) rt  = np;
  else if(np->n < rt->n)  {
    if(rt->left ==  NULL) { rt->left  = np; np->parent  = rt; }
    else insert(rt->left, np);
  }
  else  {
    if(rt->right  ==  NULL) { rt->right = np; np->parent  = rt; }
    else  insert(rt->right, np);
  }
}

node *getMax( node *rt )  {
  if(rt->right  ==  NULL) return rt;
  return getMax(rt->right);
}

node *getMin( node *rt  ) {
  if(rt->left ==  NULL) return rt;
  return getMin(rt->left);
}

node *predecessor ( node *rt  ) {
  if(rt->left) return getMax(rt->left);
  else  {
    while(rt->parent) {
      if(rt->parent->right == rt) return rt->parent;
      rt  = rt->parent;
    }
    return NULL;
  }
}

node *successor(  node *rt  ) {
  if(rt->right) return getMin(rt->right);
  else  {
    while(rt->parent) {
      if(rt->parent->left == rt)  return rt->parent;
      rt  = rt->parent;
    }
    return NULL;
  }
}

void inorder( node *rt )  {
  if(rt ==  NULL) return;
  inorder(rt->left);

  if(rt->parent)
    cout<<"Node: "<<rt->n<<", Parent: "<<rt->parent->n<<endl;
  else
    cout<<"Node: "<<rt->n<<", Parent: NULL"<<endl;
    
  inorder(rt->right);
}

void deleteNode( node *&rt, node *z ) {
  // if z has no children, then just remove it.
  if( z->left == NULL && z->right == NULL ) {
    node *p = z->parent;
    if( p == NULL ) {}
    else if(p->left == z) p->left = NULL;
    else p->right = NULL;
    delete z;
    z = NULL;
  }
  // if z has only one child, then just remove that node and connect it's child to it's parent.
  else if( z->left == NULL || z->right == NULL )  {
    node *p = z->parent;
    node *child = (z->left)?(z->left):(z->right);
    
    if( p == NULL ) rt  = child, child->parent = NULL;
    else if( p->left  ==  z ) p->left = child, child->parent = p;
    else p->right = child, child->parent = p;

    delete z;
    z = NULL;
  }
  // if z has two children
  else {
    // step 1: Pull out the successor of z.
    node *sux = successor(z);

    //To pull out, we gotta remove it from tree and yes it can not contain more than one children.
    node *pSux  = sux->parent;
    node *cSux  = (sux->left)?(sux->left):(sux->right);
    
    if(pSux == NULL)  rt  = cSux;
    else if(pSux->left  ==  sux) pSux->left = cSux;
    else pSux->right  = cSux;

    // succesor pulled out successfully!! as 'sux'

    // now, kick out 'z' and push in 'sux'.
    sux->parent = z->parent;
    sux->left = z->left;
    sux->right  = z->right;
    delete z;
    z = NULL;
  }
}

int main()  {
  int a[] = {55, 32, 61, 25, 48, 46, 59, 65}, n = 8;

  for(int i=0; i<n; i++)  insert(root, newnode(a[i]));
 
  cout<<"Before Deletion: \n"; 
  inorder(root);
  
  deleteNode(root, root->right);
  
  cout<<"\nAfter Deletion: \n";
  inorder(root);

  return 0;
}
