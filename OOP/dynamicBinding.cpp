/**
  * File Name : dynamicBinding.cpp
  *
  * Purpose :
  * Creation Date : 04-02-2011
  *
  * Last Modified : Friday 04 February 2011 11:17:52 AM IST
  *
  * Created By : Kevindra Singh <kevindra.singh@gmail.com>
  */
#include <iostream>

using namespace std;


class A{
  public:
    virtual void print()  {
      cout<<"Class A\n";
    }
};

class B:public A{
  public:
    void print()  {
      cout<<"Class B\n";
    }
};

void print2(A &a, A &b) {
  a.print();
  b.print();
}

int main()  {
  A *a, *b;

  a = new A;
  b = new B;

  print2(*a,*b);

  return 0;
}
