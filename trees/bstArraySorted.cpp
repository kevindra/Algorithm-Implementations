/**
  * File Name : bstArraySorted.cpp
  *
  * Purpose : Given an array that stores a complete Binary Search Tree, write a function that efficiently prints the given array in ascending order.
  * Creation Date : 19-05-2011
  *
  * Last Modified : Thursday 19 May 2011 04:18:40 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

void printSorted(int a[], int i, int n){
  if(i > n) return;
  printSorted(a, 2*i+1, n);
  cout<<a[i]<<" -> ";
  printSorted(a, 2*i+2, n);
}

int main(){
  int n = 5;
  int a[5] = {4,2,5,1,3};
  
  printSorted(a, 0, n-1);

  return 0;
}
