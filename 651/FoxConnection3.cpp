#line 2 "FoxConnection3.cpp"
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

class FoxConnection3 {
	public:
	long long minimalSteps(vector <int> ax, vector <int> ay) {
    int n = ax.size();
    vector<int> vx;
    vector<int> vy;
    vx.reserve(n * 2);
    vy.reserve(n * 2);
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        vx.push_back(ax[i] + ax[j] / 2);
        if(abs(ax[i] - ax[j]) % 2 != 0){
          vx.push_back(ax[i] + ax[j] / 2 + 1);
        }
        vy.push_back(ay[i] + ay[j] / 2);
        if(abs(ay[i] - ay[j]) % 2 != 0){
          vy.push_back(ay[i] + ay[j] / 2 + 1);
        }
      }
    }
    vector<int> A(n);
    for(int i = 0; i < n; ++i){
      A[i] = i;
    }
    n = vx.size();
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        do{

        }while(next_permutation(A.begin(), A.end()));
      }
    }
    for(int i = 0; i <
		long long res;
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,-2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-123456789,-58585858,-47474747,123,456,789012345}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1018530309LL; verify_case(2, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,7,3,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,7,5,3,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 12LL; verify_case(3, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-3,0,1,-2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,-3,0,1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(4, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-96277832,507856257,-86306299,-806700273,-775932643,-273209838}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-955536464,-599634138,399850429,-165706338,-537800480,738983556}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 5247213600LL; verify_case(5, Arg2, minimalSteps(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(6, Arg2, minimalSteps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  FoxConnection3 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
