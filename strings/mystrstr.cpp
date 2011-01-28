#include <iostream>

using namespace std;

char *strstr( char *a, char *b )  {
  char *ans = a;
  
  char *s1,*s2;
  s1 = a, s2 = b;

  while(*s1) {
    if( *s1 == *s2 ) {
      s1++, s2++;
    }
    else  {
      
    }
  }
}

int main()  {
  char *s1,*s2;
  s1  = "abceabcababcdefgh";
  s2  = "abcdef";

  strstr(s1,s2);
}
