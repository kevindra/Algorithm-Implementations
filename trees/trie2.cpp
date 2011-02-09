/**
  * File Name : trie2.cpp
  *
  * Purpose :
  * Creation Date : 09-02-2011
  *
  * Last Modified : Wednesday 09 February 2011 03:46:12 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct node{
  char ch;
  node *link[26]; //for 26 uppercase letters
};
node *root = NULL;

void insert(node *&root, string str , int i){
  if(i >= str.length()) return;

  if(root->link[ str[i] - 'A' ] == NULL){
    node *np = new node;
    np -> ch = str[i];
    for(int i=0;i<26;i++){
      np->link[i] = NULL;
    }
    root->link[ str[i] - 'A' ] = np;
    insert(root->link[ str[i]-'A' ] , str , i+1);
  }
  else{
    insert(root->link[ str[i] -'A' ] , str , i+1);
  }
}

void display_trie(node *root,int depth){
  if(!root){ return;}

  for(int i=0; i < depth; i++) cout<<"__";
    cout<<root -> ch<<"\n";
  for(int i = 0 ; i < 26 ; i++)
   display_trie(root->link[i], depth+1);
}

int main(){
  node *root = new node;
  root->ch = ' ';

  for(int i =0;i<26;i++){
    root->link[i] = NULL;
  }

  fstream ifile("input.txt");
  if(!ifile){ cout<<"File Not Found!!\n"; return 0;}

  while(!ifile.eof()){
    string str;
    ifile>>str;
    insert(root , str , 0);
  }

  cout<<"Root";
  display_trie(root,0);
  cout<<"\n\n";
  return 0;
}
