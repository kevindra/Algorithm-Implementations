/**
  * File Name : reverseSinglyLinkedList.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 12:34:08 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct node{
  int n;
  node *next;
};
node *start = NULL;

node *newnode( int n ) {
  node *np  = new node;
  np->n = n;
  np->next  = NULL;
  return np;
}


void insertAtFirst ( node *np ) {
  if(start == NULL) start = np;
  else  {
    np->next  = start;
    start = np;
  }
}

void display ( node *st ) {
  if( st == NULL )  { cout<<"\n"; return;  }
  cout<<st->n<<" -> ";
  display(st->next);
}


/** using two temp variables - recursive **/
void reverse ( node *st, node *prev )  {
  if( st == NULL ) return;

  start = st;
  node *next = st->next;
  st->next  = prev;
  reverse ( next, st );
}

/** using no temporary variables - recursive STACK MAGIC :) **/
node* reverseMAGIC( node *st ) {
  if( st->next != NULL ) {
    reverseMAGIC(st->next);
    st->next->next = st;
    return st;
  }
  else start = st;
}

/** PRINT THE LINKED LIST in reverse order **/
void printReverse( node *st ) {
  if(st == NULL) {  cout<<"\n"; return; }
  else {
    printReverse  ( st->next );
    cout<<st->n<<" -> ";
  }
}

/** using iterative method - reverse a linked list **/
void reverseIterative ( node *st ) {
  node *prev,*next;
  prev = NULL;
  
  while(st != NULL) {
    if(st->next == NULL) start = st;
    next = st->next;
    st->next  = prev;
    prev  = st;
    st  = next; 
  }
}

int main()  {
  int a[] = {1,2,3,4,5,6,7,8,9,10},n=10;

  for( int i = 0 ; i < n ; i++ )  {
    insertAtFirst( newnode(a[i]) );
  }

  display(start);
  //reverse(start,NULL);
  //node *end = reverseMAGIC(start);
  //end->next = NULL;

  //display(start);
  //printReverse(start);

  reverseIterative(start);
  display(start);
  return 0;
}
