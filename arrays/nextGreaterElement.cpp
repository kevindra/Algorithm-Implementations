/**
  * File Name : nextGreaterElement.cpp
  *
  * Purpose : Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.
  *
  * Creation Date : 20-05-2011
  *
  * Last Modified : Friday 20 May 2011 05:52:32 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// print Next Greater Element
void printNGE(int a[], int n){
  vector<int> v;
  v.push_back(a[0]);


  for(int i=1; i<n; i++){
    int next = a[i];
    
    if(v.size()){
      int top  = v.back();
      v.pop_back();
      while(top < next){
        cout<<top<<" -> "<<next<<endl;
        if(v.size() == 0) break;
        top = v.back();
        v.pop_back();
      } // while

      if(top > next)
        v.push_back(top);
    } //v.size

    v.push_back(next);
  } // for 
  
  while(v.size()){
    int top = v.back();
    v.pop_back();
    cout<<top<<" -> -1"<<endl;
  }
} //printNGE

int main(){
  srand((unsigned)time(0));
  int n = 5;
  int *a = new int[n];
  for(int i=0; i<n; i++) a[i] = rand()%1000;
  //sort(a,a+n);

  cout<<"Array is: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<", ";
  cout<<endl;


  printNGE(a, n);
  return 0;
}
