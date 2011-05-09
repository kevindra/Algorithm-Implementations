/**
  * File Name : isBalanced.cpp
  *
  * Purpose : Find if a tree is balanced or not.
  * Creation Date : 09-05-2011
  *
  * Last Modified : Monday 09 May 2011 03:43:08 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
  int n;
  node *left, *right;
};
node *root = NULL;

node *newnode(int n){
  node *np = new node;
  np->n = n;
  np->left = np->right = NULL;
  return np;
}

void insert(node *&root, node *np){
  if(root == NULL) root = np;
  else if(np->n < root->n) insert(root->left, np);
  else insert(root->right, np);
}

int height(node *n){
  if(n == NULL) return 0;
  return max( height(n->left), height(n->right) ) + 1;
}

bool isBalanced(node *n){
  if(n == NULL) return true;

  if(abs(height(n->left) - height(n->right)) > 1) return false;
  return isBalanced(n->left) && isBalanced(n->right);
}

void inorder(node *n){
  if(n == NULL) return;
  inorder(n->left);
  cout<<n->n<<" ";
  inorder(n->right);
}

int main(){
  //int a[] = {5,2,4,7,8,2,4,67,9,2,3,56}, n = 12;
  int a[] = {5, 3, 4, 2, 1, 8, 10, 6, 9}, n = 9;
  cout<<"Input Numbers: \n";
  
  for(int i=0; i<n; i++) insert(root, newnode(a[i]));

  cout<<"Inorder: "<<endl;
  inorder(root); cout<<endl; 
   
  cout<<"Height: "<<height(root)<<endl;
  cout<<"Is Balanced: "<<isBalanced(root)<<endl;
  return 0;
}
