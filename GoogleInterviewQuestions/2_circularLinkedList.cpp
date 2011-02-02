/**
  * File Name : 2_circularLinkedList.cpp
  *
  * Purpose : Given a sorted circular linked list and a pointer to a node. We need to insert one item such that the linked list remains sorted.
  *
  * Creation Date : 02-02-2011
  *
  * Last Modified : Wednesday 02 February 2011 12:03:29 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>

using namespace std;

struct node {
  int n;
  node *next;
};
node *start = NULL;
node *rear  = NULL;

node *newnode ( int n ) {
  node *np  = new node;
  np->n = n;
  np->next  = NULL;
  return np;
}

/** insert in circular list **/
void insertAtFirst( node *np ) {
  if(start  == NULL) {
    start = np; rear = np;
    rear->next  = start;
  }
  else {
    np->next  = start;
    rear->next  = np;
    start = np;
  }
}

void display ( node *st ) {
  while(1) {
    cout<<st->n<<" -> ";
    st = st -> next;
    if(st == rear->next) break;
  }
  cout<<endl;
}

void insert( node *given, node *np )  {
  if( (given->n == given->next->n && given->next ==  start) 
      || (given->n >  given->next->n && (np->n >= given->n || np->n <= given->next->n) )
      || ( given->n < np->n &&  np->n <= given->next->n ) ){

    //insert between given and given->next
    np->next = given->next;
    given->next = np;
  }
  else insert(given->next, np);
}

int main() {
  int a[] = {1,2,3,5,6,7,8,9,10}, n=9;

  for(int i=n-1; i>=0; i--) insertAtFirst( newnode(a[i]) );

  display( start );

  node *given = start->next->next->next;
  node *toInsert  = newnode(5);

  insert(given, toInsert);

  display( start );

  return 0;
}
