/**
  * File Name : bst_basic.cpp
  *
  * Purpose : Given root of binary search tree and K as input, find K-th smallest element in BST.
  *
  * Creation Date : 28-01-2011
  *
  * Last Modified : Thursday 19 May 2011 02:46:07 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <vector>

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

node *findKthSmallest(node *root, int k){
  /** using iterative inorder traversal **/

  vector<node *> v;

  /** go to the left extreme node (minimum) **/
  while(root){
    v.push_back(root);
    root = root->left;
  }

  while(root = v.back()){
    v.pop_back();
    if(!--k){
      break;
    }
  
    /**
      * if there is a right subtree 
      * push the left subtree of the right subtree in stack
      */
    if(root->right){
      root  = root->right;
      while(root){
        v.push_back(root);
        root  = root->left;
      } //while
    } //if root->right
  } //while root 

  if(k != 0) return NULL;
  return root;
}

/** Recursive Method **/
void kthSmallestRecursive(node *root, int &k){
  if(root == NULL || k <= 0 ) return;
  kthSmallestRecursive(root->left, k);
  if(!--k) { cout<<root->n<<" "; return; }
  kthSmallestRecursive(root->right, k);
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

  int k = 8;
  cout<<"Kth Smallest Number (Iterative Method): ";
  node *np = findKthSmallest(root, k);
  cout<<np->n<<endl;
  
  cout<<"Kth Smallest Number (Recursive Method): ";
  kthSmallestRecursive(root, k);
  //cout<<np->n<<endl;
  return 0;
}
