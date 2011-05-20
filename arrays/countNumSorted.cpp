/**
  * @author Kevindra Singh
  * @Problem: Count the number of occurrences in a sorted array
  * @desc:  Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn).
  *
  * @date: May 9, 2011
  */
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int searchL(int a[], int l, int r, int x){
  if(l <= r){
    int mid = (l+r)/2;
    
    if( a[mid] == x && (mid==0 || a[mid-1] < x) )  return mid;
    if( a[mid] == x && mid != 0 && a[mid-1] == x) return searchL(a, l, mid-1, x);

    if(x > a[mid]) return searchL(a, mid+1, r, x);
    if(x < a[mid]) return searchL(a, l, mid-1, x);
  }
  return -1;
}
int searchR(int a[], int l, int r, int x, int n){
  if(l <= r){
    int mid = (l+r)/2;
  
    if( a[mid] == x && (mid==n-1 || a[mid+1] > x) ) return mid;
    if( a[mid] == x && (mid !=n-1 && a[mid+1] == x) ) return searchR(a, mid+1, r, x, n);
    if( x > a[mid] ) return searchR(a, mid+1, r, x, n);
    if( x < a[mid] ) return searchR(a, l, mid-1, x, n);
  }
  return -1;
}

int countNum(int a[], int n, int x){
  int left  = searchL(a, 0, n-1, x);
  int right = searchR(a, 0, n-1, x, n);
  cout<<"Left : "<<left<<", Right: "<<right<<endl;
  if(left == -1 || right == -1) return 0;
  return right-left+1;
}

int main(){
  srand((unsigned)time(0));
  int n = 10;
  int *a = new int[n];
  for(int i=0; i<n; i++) a[i] = rand()%6;
  sort(a,a+n);

  cout<<"Array is: \n";
  for(int i=0; i<n; i++) cout<<a[i]<<", ";
  cout<<endl;
  
  int x = rand()%6;
  cout<<"Occurances of "<<x<<": "<<countNum(a, n, x)<<endl;
  return 0;
}
