/**
  * File Name : bst_basic.cpp
  *
  * Purpose : Write a function that returns true if the given Binary Tree is SumTree else false. 
  *   A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. 
  *   An empty tree is SumTree and sum of an empty tree can be considered as 0. 
  *   A leaf node is also considered as SumTree.
  *
  * Creation Date : 28-01-2011
  *
  * Last Modified : Friday 28 January 2011 12:51:32 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node {
  int n;
  node *left, *right;
};

node *root;

node *newnode( int n ) {
  node *np = new node;
  np->n = n;
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
    cout<<rt->n<<" -> ";
    inorder(rt->right);
  }
}

// O(n) Solution
bool isLeaf(node *root){
  if(root == NULL) return false;
  if(root->left == NULL && root->right == NULL) return true;
  return false;
}

bool isSumTree(node *root){
  if(root == NULL) return false;

  if(isSumTree(root->left) && isSumTree(root->right)){
    int ls, rs;
    /** find the sum of left subtree **/
    if(root->left == NULL) ls = 0;
    else if(isLeaf(root->left)) ls = root->left->n;
    else ls = 2 * (root->left->n);

    /** find the sum of the right subtree **/
    if(root->right == NULL) rs  = 0;
    else if(isLeaf(root->right)) rs = root->right->n;
    else rs = 2 * (root->right->n);

    return (root->n == ls + rs);
  }
  return false;
}

int main() {
  int a[] = {26, 10, 30, 30, 4, 6}, n = 6;

  cout<<"Input Numbers: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<" ";
  cout<<endl;


  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder : \n";
  inorder(root);
  cout<<endl;

  cout<<"Is Sum Tree: "<<isSumTree(root)<<endl;
  return 0;
}
