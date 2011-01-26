#include <iostream>

using namespace std;

struct node {
  int n;
  node *next,*prev;
};
node *start = NULL;
node *end   = NULL;

node * newnode ( int n ) {
  node *np = new node;
  np->n = n;
  np->next = NULL;
  np->prev = NULL;
  return np;
}

void insertAtFirst( node *np ) {
  if(start == NULL) start = np, end = np;
  else  {
    np->next = start;
    start->prev = np;
    start = np;
  }
}

void displayForward ( node *st ) {
  if( st == NULL ) return;
  cout<<st->n<<" -> ";
  displayForward( st->next );
}

void displayBackward ( node *end ) {
  if( end == NULL ) return;
  cout<<end->n<<" -> ";
  displayBackward( end->prev );
}

/** STACK MAGIC -> reverse without using any temporary variable **/
void reverse ( node *st, node *end ) {
  if( st->next != NULL )  {
    reverse (st->next,end->prev);
    st->next->next = st;
    end->prev->prev = end;
  }
  else start = st, ::end = end;
}

int main()  {
  int a[] = {1,2,3,4,5,6,7,8,9,10}, n=10;

  for ( int i = 0; i < n; i++ ) {
    insertAtFirst ( newnode(a[i]) );
  }

  cout<<" Forward: "; displayForward(start);
  cout<<"\n Backward: "; displayBackward(end);
  
  reverse(start,end);
  start->prev=NULL;
  end->next = NULL;

  cout<<"\n After reversing: \n  ";
  cout<<"\n Forward : ";  displayForward(start);
  cout<<"\n Backward: "; displayBackward(end);

  return 0;
}
