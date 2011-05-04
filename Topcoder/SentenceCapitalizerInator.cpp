// BEGIN CUT HERE 
// END CUT HERE
#line 4 "SentenceCapitalizerInator.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define fori(type,x,a,b) for( type (x) = (a) ; (x) < (b) ; (x)++)
#define forr(type,x,a,b) for( type (x) = (a) ; (x) >= (b) ; (x)--)
#define FI(x,a,b) fori(int,x,a,b)
#define FRI(x,a,b) forr(int,x,a,b)
#define FLL(x,a,b) fori(long long,x,a,b)
#define FRLL(x,a,b) forr(long long,x,a,b)
#define fill(x,v,n) memset((x),(v),n*sizeof(x));

typedef unsigned long long ull;
typedef long long ll;

const double pi = acos(-1.0);

class SentenceCapitalizerInator{ 
  public: 
  string fixCaps(string para){ 
    para[0] = toupper(para[0]);
    int pos=-1;
    while(true){
      pos = para.find(". ",pos+1);
      if(pos == string::npos) break;
      if(pos < para.size()-2) para[pos+2] = toupper(para[pos+2]);
    }
    return para;
  } 
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello programmer. welcome to topcoder."; string Arg1 = "Hello programmer. Welcome to topcoder."; verify_case(0, Arg1, fixCaps(Arg0)); }
	void test_case_1() { string Arg0 = "one."; string Arg1 = "One."; verify_case(1, Arg1, fixCaps(Arg0)); }
	void test_case_2() { string Arg0 = "not really. english. qwertyuio. a. xyz."; string Arg1 = "Not really. English. Qwertyuio. A. Xyz."; verify_case(2, Arg1, fixCaps(Arg0)); }
	void test_case_3() { string Arg0 = "example four. the long fourth example. a. b. c. d."; string Arg1 = "Example four. The long fourth example. A. B. C. D."; verify_case(3, Arg1, fixCaps(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main(){
  SentenceCapitalizerInator ___test; 
  ___test.run_test(-1); 
  system("pause");
} 
// END CUT HERE 
