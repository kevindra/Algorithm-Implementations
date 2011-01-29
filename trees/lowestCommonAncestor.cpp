/**
  * File Name : leastCommonAncestor.cpp
  *
  * Purpose :
  * Creation Date : 29-01-2011
  *
  * Last Modified : Saturday 29 January 2011 10:05:52 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  int level;
  node *left, *right;
};

node *root;

node *newnode( int n ) {
  node *np = new node;
  np->n = n;
  np->level = 0;
  np->left  = NULL;
  np->right = NULL;
  return np;
}

void insert ( node *&rt, node *np ) {
  if( rt == NULL ) rt = np;
  else if( np->n >= rt->n ) insert(rt->right, np);
  else insert(rt->left, np);
}

void inorder( node *rt ) {
  if(rt != NULL) {
    inorder(rt->left);
    cout<<"("<<rt->n<<", "<<rt->level<<") -> ";
    inorder(rt->right);
  }
}

void generateLevel(node *&rt, int level){
  if(rt == NULL) return;

  generateLevel(rt->left, level+1);
  rt->level = level;
  generateLevel(rt->right, level+1);
}

/** least common ancestor **/
node *lca(node *rt, node *n1, node *n2) {
  while(rt) {
    //cout<<"-> "<<rt->n<<" "<<n1->n<<" "<<n2->n<<endl;
    if( (n1->n >= rt->n && n2->n < rt->n) || (n1->n < rt->n && n2->n >= rt->n) )  {
      return rt;
    }
    else if(n1->n >= rt->n) rt = rt->right;
    else rt = rt->left;
  }

  return NULL;
}

node *find(node *rt, int val){
  if(rt == NULL) return NULL;
  else if(rt->n == val) return rt;
  else if(val >= rt->n) return find(rt->right, val);
  else return find(rt->left, val);
}

int main() {
  int a[] = {5,2,4,7,8,2,4,67,9,2,3,56}, n = 12;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  generateLevel(root, 0);

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  node *A = find(root, 7);
  node *B = find(root, 4);

  node *L = lca(root, A, B);
  if(L == NULL) cout<<"Error\n";
  else cout<<"Lowest Common Ancestor to "<<A->n<<" & "<<B->n<<": "<<L->n<<endl;
  return 0;
}
