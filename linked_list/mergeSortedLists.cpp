/**
  * File Name : mergeSortedLists.cpp
  *
  * Purpose :
  * Creation Date : 04-02-2011
  *
  * Last Modified : Friday 04 February 2011 05:02:18 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
  int n;
  node *next;
};

node *start1  = NULL;
node *start2  = NULL;

node *newnode( int n )  {
  node *np  = new node;
  np->n = n;
  np->next  = NULL;
  return np;
}

void insertAtFirst(node *&st, node *np)  {
  if(st ==  NULL) st  = np;
  else {
    np->next  = st;
    st  = np;
  }
}

void insertAtEnd(node *&st, node *&end, node *np)  {
  if(st == NULL) st = end = np;
  else {
    end->next = np;
    end = end->next;
  }
}

void merge( node *st1, node *st2, node *&res, node *&end ) {
  while(st1&&st2) {
    int a;
    if(st1->n > st2->n) a=st2->n, st2=st2->next;
    else a=st1->n, st1=st1->next;
    
    insertAtEnd(res, end, newnode(a));
  }

  if( !(st1||st2) ) return;

  if(st1) while(st1) {
    insertAtEnd(res, end, newnode(st1->n));
    st1 = st1->next;
  }
  if(st2) while(st2) {
    insertAtEnd(res, end, newnode(st2->n));
    st2 = st2->next;
  }
}

void display(node *st){
  if(st ==  NULL) return;
  
  cout<<st->n<<" -> ";
  display(st->next);
}


int main()  {
  int a[] = {3,4,5,6,8,9,10,13,14,15}, n1=10;
  int b[] = {1,2,3,4,7,7,8,10,11,12}, n2=10;
  
  for(int i=n1-1; i>=0; i--)  insertAtFirst(start1, newnode(a[i]));
  for(int i=n2-1; i>=0; i--)  insertAtFirst(start2, newnode(b[i]));

  cout<<"List 1: "; display(start1);  cout<<endl;
  cout<<"List 2: "; display(start2);  cout<<endl;

  node *res = NULL, *end = NULL;
  merge(start1, start2, res, end);
  
  cout<<"Merge List: "; display(res); cout<<endl;
  
  return 0;
}
