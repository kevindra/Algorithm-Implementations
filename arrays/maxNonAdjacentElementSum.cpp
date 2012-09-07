/**
  * Purpose : Given an array, find out the max sum of its elements such that no two elements are adjacent in the array.
  *
  * Creation Date : 07-09-2012
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

int maxsum(int a[], int i, int n)
{
	if( i > n-1) return 0;

    return max (a[i] + maxsum(a,i+2,n), a[i] + maxsum(a,i+3,n));
}

int main()
{
	//int a[] = {0,5,1,6,12,4,1,2};
	int a[] = {10,5,1,6,12,4,1,3};
	int n = 8;

	cout<<"Max sum: " <<max( maxsum(a,0,n), maxsum(a,1,n) )<<endl;

	cin>>n;
}