/**
  * File Name : maxSubArraySum.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 01:34:58 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>

using namespace std;

int maxSubArraySum ( int *a,  int n ) {
  int maxSum = -1;
  int curMaxSum = 0;

  for( int i = 0; i < n; i++) {
    curMaxSum += a[i];
    if( curMaxSum < 0 ) curMaxSum = 0;
    maxSum = max( curMaxSum, maxSum );
  }
  return maxSum;
}

int main()  {
  int a[] = {11, -12, 15, -3, 8, -9, 1, 8, 10, -2}, n=10;
  
  int maxSum = maxSubArraySum( a, n );

  cout<<"Max sum: "<<maxSum<<endl;

  return 0;
}
