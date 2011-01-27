/**
  * File Name : swapNibbles.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 06:52:41 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

void printBits(char c) {
  if((int)c==0) return;
  int bit = ((int)c)&0x1;
  printBits(((int)c)>>1);
  cout<<bit;
}

char swap ( char ch ) {
  char left,right;
  left = ch & 0xF0;
  right = ch & 0x0F;

  return ((right<<4)|(left>>4));
}


int main() {
  char ch = 'a';
  char ch_  = swap(ch);

  cout<<"Original nibbles: ";
  printBits(ch);
  cout<<endl;

  cout<<"Swapped nibble: ";
  printBits(ch_);
  cout<<endl;

  return 0;
}
