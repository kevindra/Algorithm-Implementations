/**
  * File Name : editDistance.cpp
  *
  * Purpose :
  * Creation Date : 28-02-2011
  *
  * Last Modified : Monday 28 February 2011 10:52:31 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int **allocate2DArray(int r, int c) {
  int **m = (int**)malloc(sizeof(int)*r*c);
  for(int i=0; i<r; i++) m[i] = (int*) malloc(sizeof(int)*c);

  return m;
}

int editDistance( string a, string b )  {
  int **dp = allocate2DArray(a.length()+1, b.length()+1);  

  for(int i=0; i<a.length()+1; i++) dp[i][0] = i;
  for(int i=0; i<b.length()+1; i++) dp[0][i] = i;

  for(int i=0; i<a.length(); i++) {
    for(int j=0; j<b.length(); j++) {
      if( a[i] == b[j] ) dp[i+1][j+1] = dp[i][j];
      else {
        dp[i+1][j+1] = min ( dp[i][j], min( dp[i][j+1], dp[i+1][j] ) ) + 1;
      }
    }
  }

  return dp[a.length()][b.length()];
}

int main() {
  string a,b;
  a = "asfasdfsafsadfhgfhdfhjdjdf";
  b = "asdfgdhfgdfdsf";

  cout<<"Edit Distance: "<<editDistance(a,b)<<endl;

  return 0;
}
