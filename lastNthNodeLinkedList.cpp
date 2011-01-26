#include <iostream>

using namespace std;

struct node {
  int n;
  node *next;
};
node *start = NULL;


node *newnode ( int n ) {
  node *np  = new node;
  np->n = n;
  np->next  = NULL;
  return np;
}

void insertAtFirst( node *np )  {
  if(start  == NULL) start  = np;
  else np->next = start, start  = np;
}

void display ( node *start )  {
  if(start == NULL) return;
  cout<<start->n<<" -> ";
  display(start->next);
}

node *lastNthNode( node *start, int pos ) {
  if(!start) return NULL;

  node *p1=start,*p2=start;
  for(int i=0; i<pos && p2; p2=p2->next,i++);

  if(!p2) return NULL;

  while(p2) {
    p1=p1->next, p2=p2->next;
  }
  return p1;
}

int main () {
  for(int i=0; i<10; i++) insertAtFirst( newnode(i) );
  
  cout<<"List: "; display(start);

  int last  = 6;
  node *ret = lastNthNode(start,last);

  cout<<endl;
  if(ret) cout<<last<<"th node for last: "<<ret->n<<endl; 
  else  cout<<"Position doesnot exist"<<endl;

  return 0;
}
