/**
  * File Name : findMissingDuplicate.cpp
  *
  * Purpose : Given an unsorted array of size n. Array elements are in range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in array. Find these two numbers.
  *
  * Creation Date : 20-05-2011
  *
  * Last Modified : Friday 20 May 2011 03:31:04 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

void findMissingDuplicate(int a[], int n, int &x, int &y){
  int xor1 = a[0];
  x = y = 0;
  for(int i=1; i<n; i++) xor1 ^= a[i];
  for(int i=1; i<=n; i++) xor1  ^= i;

  //xor1 = x^y where x and y are missing and duplicate elements.
  //Now find any set bit of this xor1, lets assume it rightmost set bit
  int set_bit = xor1 & ~(xor1 - 1);
  
  for(int i=0; i<n; i++){
    if(a[i] & set_bit)  x ^= a[i]; //first set
    else y ^= a[i]; //second set
  }
  
  for(int i=1; i<=n; i++){
    if(a[i] & set_bit) x ^= i;
    else y ^= i;
  }
}

int main(){
  int a[] = {3, 1, 3}, n = 3;
  int x, y;

  findMissingDuplicate(a, n, x, y);
  cout<<"Missing and Duplicate Number: "<<x<<" "<<y<<endl;
  return 0;
}
