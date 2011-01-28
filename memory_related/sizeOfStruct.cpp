/**
  * File Name : sizeOfStruct.cpp
  *
  * Purpose :
  * Creation Date : 27-01-2011
  *
  * Last Modified : Thursday 27 January 2011 05:12:17 PM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;

struct s1 {
  int a,b,c;
};

struct s {
  char c;
  s1 obj;
  int a;
};

/**
  * Learn how to calculate size of structure manually: 
  * http://www.codeguru.com/forum/showthread.php?t=276622
  * 
  * It actually depends on compiler, 
  *
  * In above code.. struct s1 contains 3 integers - that means 4+4+4 = 12 (memory should be in power of 2)
  * in structure s2, it contains three data members:
  * 1. character: 1 byte
  * 2. struct s1: 12 bytes
  * 3. integer:   4 bytes
  *
  * that means (12+1+4) or (12+1) + 4 = (13)+4 
  * since memory shall be power of two
  * hence it should be : 13 + (3-padding) + 4 = 16+4 = 20 bytes total.
  * 
  * Visit above forum link to find more information regarding this. 
  **/

int main () {
  s *p = NULL;
  
  cout<<p+1<<" "<<p<<endl;  
  cout<<"Size of struct: "<< ((char*)(p+1) - (char*)p) <<endl;
  return 0;
}
