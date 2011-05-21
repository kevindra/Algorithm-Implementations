/**
  * author: Kevindra Singh
  * Desc: Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
  */

#include<iostream>

using namespace std;

int getEquilibriumIndex(int a[], int n){
  int leftSum=0, rightSum=0, totalSum=0;

  for(int i=0; i<n; i++) totalSum += a[i];
  
  rightSum = totalSum;
  for(int i=0; i<n; i++){
    rightSum -= a[i];
    if(leftSum == rightSum) return i;
    leftSum += a[i];
  }
  return -1;
}

int main(){
  int a[] = {-7, 1, 5, 2, -4, 3, 0}, n =7;
  cout<<"equilibrium index: "<<getEquilibriumIndex(a, n)<<endl;
  return 0;
}
