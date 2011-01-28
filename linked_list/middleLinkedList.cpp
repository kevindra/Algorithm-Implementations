/**
  * File Name : middleLinkedList.cpp
  *
  * Purpose :
  * Creation Date : 26-01-2011
  *
  * Last Modified : Wednesday 26 January 2011 12:33:30 PM IST
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

node *newnode (int n) {
  node *np  = new node;
  np->n = n;
  np->next  = NULL;
  return np;
}

void insertAtFirst ( node *np ) {
  if(start == NULL) start = np;
  else np->next = start, start  = np;
}

void display( node *start ) {
  if(start == NULL) return;
  cout<<start->n<<" -> ";
  display(start->next);
}

node *findMiddle( node *start )  {
  node *middle = start;
  for (int i=0; start; start=start->next, i++)  {
    if(i%2)  {
      middle = middle->next;
    }
  }
  return middle;
}

int main()  {
  int a[] = {1,2,3,4,5,6,7,8,9,10},n=10;

  for ( int i=0; i<n; i++)  {
    insertAtFirst( newnode(a[i]) );
  }
  cout<<"List: "; display(start); cout<<endl;
  
  node *mid = findMiddle(start);
  cout<<"Middle: "<<mid->n<<endl;
  return 0;
}
