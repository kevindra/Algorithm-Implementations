#include <iostream>

using namespace std;


struct node{
  int v;
  node *next;
};
node *start = NULL;
node *end = NULL;

node *newNode(int v){
  node *np = new node;
  np->v = v;
  np->next  = NULL;
  return np;
}

/** Returns the XOR of two Nodes **/
node *XOR(node *a, node *b){
  return (node *)((long long)(a)^(long long)(b));
}

void insert(node *current, node *prev, node *np){
  /** if linked list is empty **/
  if(start == NULL){
    np->next = XOR(prev, NULL); 
    start = np;
    end = np;
  }
  else if( XOR(prev, current->next) == NULL ){ //end node of the linked list
    current->next = XOR(prev,np);
    np->next      = XOR(current, NULL);
    end = np;
  }
  else{ // move forward
    insert( XOR(prev, current->next), current, np);
  }
}

void displayForward(node *start, node *prev){
  if(start == NULL) return;

  cout<<start->v<<" -> ";
  displayForward( XOR(start->next, prev), start);
}

void displayBackward(node *end, node *prev){
  if(end == NULL) return;

  cout<<end->v<<" -> ";
  displayBackward( XOR(end->next, prev), end);
}

int main(){
  int a[] = {1,2,3,4,5,6,7,8,9,10}, n = 10;

  for(int i=0; i<n; i++){
    node *prev = NULL;
    insert(start, prev, newNode(a[i]));
  }

  cout<<"Forward: \n";
  node *prev=NULL;
  displayForward(start, prev);

  cout<<"\nBackward: \n";
  displayForward(end, prev);
  return 0;
}
