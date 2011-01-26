#include <iostream>

using namespace std;


struct node {
  int n;
  node *next;
};
node *start = NULL;


node *newnode ( int n ) {
  node *np = new node;
  np->n = n;
  np->next = NULL;
  return np;
}

void insertAtFirst ( node * np ) {
  if(start == NULL) start = np;
  else {
    np->next = start;
    start = np;
  }
}

void display( node *st ) {
  if( st == NULL ) return;

  cout<<st->n<< " -> ";
  display(st->next);
}

/** bubble sort using only value swapping **/
void bubbleSort ( node *st ) {
  node *i,*j;
  i = st,j=st;

  for(; i->next != NULL; i = i->next) {
    for( j=i->next; j != NULL; j = j->next ) {
      if( i->n > j->n ) {
        swap(i->n,j->n);
      }
    }
  }
}

void swapnode( node *i, node *j ) {
  
}

/** bubble sort using pointer swapping **/
void bubbleSortAdvanced ( node *st ) {
  node *i, *j;
  
  for( i = st; i->next != NULL; i = i->next ) {
    for( j = i->next; j != NULL; j = j->next ) {
      if( i->n > j->n ) {
        swapnode(i,j);
      }
    }
  }
}

void bubble ( int a[], int n ) {
  for(int i=0;i<n;i++)  {
    for(int j=i+1; j<n; j++) {
      if(a[i]>a[j]) swap(a[i],a[j]);
    }
  }
}

int main() {
  int a[] = {2,4,6,1,2,4,7,9,7,8}, n=10;

  for(int i = 0; i <= n; i++) {
    insertAtFirst( newnode(a[i]) );
  }

  cout<<"\nBefore sorting:  "; display(start);
  bubbleSort(start);
  cout<<"\nAfter sorting: "; display(start);

  return 0;
}
