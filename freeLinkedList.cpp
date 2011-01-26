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

void freeAllList( node *start ) {
  if(start == NULL) return;
  freeAllList(start->next);
  delete start;
/*  node *curNode, *nextNode;
  for(curNode=start; curNode; curNode = nextNode){
    nextNode  = curNode->next;
    delete curNode;
  }*/
}

int main()  {
  int a[] = {1,2,3,4,5,6,7,8,9,10},n=10;

  for ( int i=0; i<n; i++)  {
    insertAtFirst( newnode(a[i]) );
  }
  cout<<"List Before: "; display(start); cout<<endl;
  freeAllList(start);
  cout<<"List After: "; display(start); cout<<endl;
  
  return 0;
}
