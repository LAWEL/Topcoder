#line 2 "SegmentDrawing.cpp"
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

class SegmentDrawing {
	public:
	int maxScore(vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore) {
		int res;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3,
 1, 0, 6, 4,
 2, 6, 0, 5,
 3, 4, 5, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 3, 7,
 2, 0, 4, 6,
 3, 4, 0, 5,
 7, 6, 5, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 27; verify_case(0, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 101, 101, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 100, 100, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 101; verify_case(1, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {-3, -1, -1,  1,  1,  3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, -2,  2, -2,  2,  0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 1, 2, 1, 2,
 2, 0, 2, 1, 2, 1,
 1, 2, 0, 2, 1, 2,
 2, 1, 2, 0, 2, 1,
 1, 2, 1, 2, 0, 2,
 2, 1, 2, 1, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 21, 0, 0,
 0, 0, 21, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 25; verify_case(2, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {-100, 100, 0, -10, 10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 10, 10, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 96, 96, 25, 25, 25,
 96,  0, 96, 25, 25, 25,
 96, 96,  0, 25, 25, 25,
 25, 25, 25,  0, 10, 10,
 25, 25, 25, 10,  0, 10,
 25, 25, 25, 10, 10,  0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 30, 30, 20, 20, 20,
 30,  0, 30, 20, 20, 20,
 30, 30,  0, 20, 20, 20,
 20, 20, 20,  0, 86, 86,
 20, 20, 20, 86,  0, 86,
 20, 20, 20, 86, 86,  0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 546; verify_case(3, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9,
 15, 0, 15, 2, 3, 4, 5, 6, 7, 8,
 2, 15, 0, 15, 2, 3, 4, 5, 6, 7,
 3, 2, 15, 0, 15, 2, 3, 4, 5, 6,
 4, 3, 2, 15, 0, 15, 2, 3, 4, 5,
 5, 4, 3, 2, 15, 0, 15, 2, 3, 4,
 6, 5, 4, 3, 2, 15, 0, 15, 2, 3,
 7, 6, 5, 4, 3, 2, 15, 0, 15, 2,
 8, 7, 6, 5, 4, 3, 2, 15, 0, 15,
 9, 8, 7, 6, 5, 4, 3, 2, 15, 0}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9,
 0, 0, 0, 2, 3, 4, 5, 6, 7, 8,
 2, 0, 0, 0, 2, 3, 4, 5, 6, 7,
 3, 2, 0, 0, 0, 2, 3, 4, 5, 6,
 4, 3, 2, 0, 0, 100, 2, 3, 4, 5,
 5, 4, 3, 2, 100, 0, 0, 2, 3, 4,
 6, 5, 4, 3, 2, 0, 0, 0, 2, 3,
 7, 6, 5, 4, 3, 2, 0, 0, 0, 2,
 8, 7, 6, 5, 4, 3, 2, 0, 0, 0,
 9, 8, 7, 6, 5, 4, 3, 2, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 300; verify_case(4, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SegmentDrawing ___test;
  ___test.run_test(-1);
}
// END CUT HERE
