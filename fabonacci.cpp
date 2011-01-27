/**
  * File Name : fibonacci.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 12:38:58 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <stdlib.h>

using namespace std;

/** brute force method **/
long long fibonacci ( int n ) {
  if( n <=0 ) return 0;
  if( n==1||n==2 ) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}

/** using memoization **/
int dp[50] = {0};
long long fibonacciDP ( int n ) {
  if( n <= 0 ) return 0;
  if( n==1 || n==2 )  return dp[1] = dp[2] = 1;
  
  if( dp[n] != 0 )  return dp[n];
  else return dp[n] = fibonacciDP(n-1) + fibonacciDP(n-2);
}

/** using matrix **/
/** The n-th of a matrix can be computed efficiently in O(logn) time. This implies an O(logn) algorithm for computing the nth Fibonacci number.**/
int **mul( int **m1, int **m2 ) {
  int **ret = (int**)malloc(sizeof(int**)*4);
  for(int i=0;i<2;i++) ret[i] = (int*)malloc(sizeof(int)*2);

  ret[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
  ret[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
  ret[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
  ret[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];
  return ret;
}
/** nth power of this matrix gives {{F(n+1), F(n)},{F(n), F(n-1)}} **/

/** we can caculate n-th power in logn time using divide and conquer technique **/
int **powMat ( int **a, int n )  {
  int **ret = (int**)malloc(sizeof(int**)*4);
  for(int i=0;i<2;i++) ret[i] = (int*)malloc(sizeof(int)*2);

  if(n <= 0)  {
    ret[0][0] = 1, ret[0][1] = 0, ret[1][0] = 0, ret[1][1] = 0;
    return ret;
  }
  if(n == 1)  {
    ret[0][0] = 1, ret[0][1] = 1, ret[1][0] = 1, ret[1][1] = 0;
    return ret;
  }
  if(n == 2) {
    ret[0][0] = 2, ret[0][1] = 1, ret[1][0] = 1, ret[1][1] = 1;
    return ret;
  }

  if(n%2 == 0) {
    int **m = powMat( a, n/2 );
    return mul(m,m);
  }
  else {
    int **m = powMat( a, n/2 );
    m = mul(m,m);
    m = mul(m,a);
    return m;
  }
}


int main() {
  cout<<"Brute force method: \n";
  for (int i = 0 ; i < 20; i++) cout<<fibonacci(i)<<" ";
  cout<<endl<<"Dynamic Programming: \n";
  for (int i = 0 ; i < 20; i++) cout<<fibonacciDP(i)<<" ";
  cout<<endl;


  int **mat = (int**)malloc(sizeof(int**)*4);
  for(int i=0;i<2;i++) mat[i] = (int*)malloc(sizeof(int)*2);
  mat[0][0] = 1, mat[0][1] = 1, mat[1][0] = 1, mat[1][1] = 0;

  cout<<"Using matrix(best): \n";
  for(int i=0; i < 20; i++) {
    int **m = powMat(mat, i);
    cout<<m[0][1]<<" ";
  }
  cout<<endl;
  return 0;
}
