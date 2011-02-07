/**
  * File Name : combinator.cpp
  *
  * Purpose :
  * Creation Date : 07-02-2011
  *
  * Last Modified : Monday 07 February 2011 07:48:32 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

void combinate( int a[], int n )  {
  cout<<"Combinations: \n";
  for(int i=0; i<(1<<n); i++)  {
    for(int j=0; j<n; j++){
      if( (i&(1<<j)) > 0 )  cout<<a[j]<<" ";
    }
    cout<<endl;
  }
}

int main()  {
  int a[] = {1,2,3,4,5}, n = 5;

  combinate(a, n);
  return 0;
}
