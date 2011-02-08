/**
  * File Name : bstDeleteNode.cpp
  *
  * Purpose :
  * Creation Date : 07-02-2011
  *
  * Last Modified : Tuesday 08 February 2011 07:26:06 PM IST
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

/** Pulls out the node having no children **/
node *pullOutChildless(node *&rt, node *z) {
  node *p = z->parent;
  
  if(p == NULL) rt  = NULL;
  else if(p->left == z) p->left = NULL;
  else p->right = NULL;

  return z;
}

node *pullOutSingleChildParent(node *&rt, node *z) {
  node *p = z->parent;
  node *child = (z->left)?(z->left):(z->right);

  if(p==NULL) {
    rt  = child;
    rt->parent = NULL;
  }
  else if(p->left == z) {
    p->left = child;
    child->parent = p;
  }
  else {
    p->right  = child;
    child->parent = p;
  }

  return z;
}

node *pullOutTwoChildParent(node *&rt, node *z) {
  node *s = successor(z);
  
  // Successor can not have more than two children,   
  // because if it has then it can't be a successor
  // now, pullout successor
  if( s->left == NULL && s->right == NULL )
    s = pullOutChildless(rt, s);
  else
    s = pullOutSingleChildParent(rt, s);
 
  node *p = z->parent;
  if(p && p->right == z) p->right = s;
  else if(p && p->left == z) p->left = s;
  else rt = s;

  s->left   = z->left;
  s->right  = z->right;
  s->parent = z->parent;
  
  if(s->left) s->left->parent = s;
  if(s->right) s->right->parent = s;
 
  return z;
}

void deleteNode( node *&rt, node *z ) {
  // if z has no children, then just remove it.
  if( z->left == NULL && z->right ==  NULL  ) {
    node *p = pullOutChildless(rt, z);
    delete p;
    p = NULL;
  }
  else if( z->left == NULL || z->right == NULL )  {
    node *p = pullOutSingleChildParent(rt, z);
    delete p;
    p = NULL;
  }
  else {
    node *p = pullOutTwoChildParent(rt, z);
    delete p;
    p = NULL;
  }
}

int main()  {
  int a[] = {55, 32, 61, 25, 48, 46, 59, 65}, n = 8;
  //int a[] = {5,4,6}, n = 3;

  for(int i=0; i<n; i++)  insert(root, newnode(a[i]));
 
  cout<<"Before Deletion: \n"; 
  inorder(root);
  
  deleteNode(root, root);
  
  cout<<"\nAfter Deletion: \n";
  inorder(root);

  return 0;
}
