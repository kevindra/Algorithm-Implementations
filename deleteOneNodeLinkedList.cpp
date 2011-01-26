/**
  * File Name : deleteOneNodeLinkedList.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 12:32:47 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
/**
  * @author kevindra
  *
  * Problem: Given only a pointer to a node to be deleted in a singly linked list,
  *          how do you delete it?
  */

#include <iostream>

using namespace std;

struct node {
  int val;
  node *next;
};
node *start = NULL;

node *newnode( int n ) {
  node *np = new node;
  np->val = n;
  np->next  = NULL;
  return np;
}

void insertAtFirst ( node *np ) {
  if(start == NULL) start = np;
  else {
    np->next = start;
    start = np;
  }
}

void display (node* st) {
  if(st==NULL) return;
  cout<<st->val<<" -> ";
  display(st->next);
}

/** deletes a node from the linked list **/
void deleteNode( node *st, int n ) {
  if( st->val == n ) {  start = st->next; return; }

  if( st->next == NULL ) return;
  if( st->next->val == n ) {
    st->next = st->next->next;
  }
  
  if(st->next != NULL)  deleteNode(st->next, n);
}

int main()  {
  int a[] = {1,2,3,4,5,6,7,8,9,10}, n=10;

  for( int i = 0 ; i < n ; i++ )  {
    insertAtFirst( newnode(a[i]) );
  }
  
  cout<<"LinkedList: ";
  display(start);
  cout<<"\n";

  deleteNode(start, 10);

  cout<<"After Deletion: ";
  display(start);
  cout<<"\n";

  return 0;
}
