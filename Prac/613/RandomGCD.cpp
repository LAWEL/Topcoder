#line 2 "RandomGCD.cpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
#include <sstream>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <stack>
#include <cctype>
#include <iomanip>

using namespace std;

typedef long long lli;

const double EPS = 1e-8;

class RandomGCD {
	public:
	int countTuples(int N, int K, int low, int high) {
		int res;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 4; int Arg4 = 3; verify_case(0, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 2; int Arg3 = 4; int Arg4 = 0; verify_case(1, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 73824; int Arg1 = 17347; int Arg2 = 9293482; int Arg3 = 9313482; int Arg4 = 0; verify_case(3, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 222; int Arg1 = 222; int Arg2 = 222; int Arg3 = 22222; int Arg4 = 339886855; verify_case(4, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  RandomGCD ___test;
  ___test.run_test(-1);
}
// END CUT HERE
