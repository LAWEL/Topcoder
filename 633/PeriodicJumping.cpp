#line 2 "PeriodicJumping.cpp"
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

class PeriodicJumping {
public:
  int minimalTime(int x, vector <int> jumpLengths) {
    x = abs(x);
    if(x == 0) return 0;
    if(jumpLengths.size() == 1) {
      if(x == jumpLengths[0]) return 1;
      else return 2;
    }
    long long sum = 0;
    for(int hoge : jumpLengths) {
      sum += hoge;
    }
    int res = 0;
    long long tmp = 0;
    for(; tmp + sum < x; tmp += sum, res += jumpLengths.size());
    size_t pos = 0;
    x -= tmp;
    if(x <= jumpLengths[0]) {
      return res + 1;
    }
    cout << "res = " << res << endl;
    cout << "x = " << x << endl;
    sum = 0;
    vector<int> vec;
    for(int i = 0; i < jumpLengths.size() * 2; ++i) {
      int idx = i % jumpLengths.size();
      sum += jumpLengths[idx];
      vec.push_back(jumpLengths[idx]);
      res++;
      if(sum +  < x) continue;
      sort(vec.begin(), vec.end());
      reverse(vec.begin(), vec.end());
      long long tt = 0;
      for(size_t j = 0; j < vec.size(); ++j) {
        if(abs(tt + vec[j] - x) <= abs(tt - vec[j] - x)) {
          tt += vec[j];
        } else {
          tt -= vec[j];
        }
      }
      cout << i << ", " << idx << ", " << tt << endl;
      if(abs(tt - jumpLengths[(idx + 1) % jumpLengths.size()]) <= x) {
        return res + 1;
      }
    }
    return res;
  }

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -10; int Arr1[] = {2,3,4,500,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(3, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = -1000000000; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000000000; verify_case(4, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {19911120}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, minimalTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  PeriodicJumping ___test;
  ___test.run_test(3);
}
// END CUT HERE
