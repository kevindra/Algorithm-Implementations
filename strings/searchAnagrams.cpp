/**
  * File Name : searchAnagrams.cpp
  *
  * Purpose :
  * Creation Date : 25-02-2011
  *
  * Last Modified : Friday 25 February 2011 01:05:24 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

map<int,int> m;
void preProcessList( vector<string> s ) {
  cout<<"Word\tMask\n";
  for(int i=0; i<s.size(); i++) {
    int mask  = 0;
    for(int j=0; j<s[i].size(); j++) {
      mask |= (1<<(s[i][j]-'a'));
    }
    cout<<s[i]<<"\t"<<mask<<endl;
    m[mask] += 1;
  } 
}

int numOfAnagrams ( string s ) {
  int mask  = 0;
  for(int i=0; i<s.size(); i++) mask |= (1<<(s[i]-'a'));

  return m[mask];
}

int main() {
  vector<string> input;
  freopen("anagrams.in", "r", stdin);

  string s;
  while(cin>>s) input.push_back(s);

  string word = "abc";

  preProcessList(input);

  int anagrams =  numOfAnagrams(word);

  cout<<"Anagrams of "<<word<<" in list: "<<anagrams<<endl;
  return 0;  
}
