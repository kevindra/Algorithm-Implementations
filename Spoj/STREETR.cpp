/**
  * File Name : STREETR.cpp
  *
  * Purpose :
  * Creation Date : 17-03-2011
  *
  * Last Modified : Thursday 17 March 2011 06:21:21 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}

int main() {
  ll N;
  cin>>N;

  int first = 1;
  ll x1;
  vector<ll> d;
  while(N--){
    ll x;
    cin>>x;
    if(first) x1 = x, first=0;
    else d.push_back(x-x1), x1 = x;
  }

  
  ll g = -1;
  for(int i = 1; i<d.size(); i++){
    if( g==-1 ) g = gcd(d[0],d[i]);
    else  g = gcd(g,d[i]);
  }

  ll ans = 0;
  for(int i=0; i<d.size(); i++) {
    ans += (d[i]/g) - 1;
  }

  cout<<ans<<endl;
  return 0;
}
