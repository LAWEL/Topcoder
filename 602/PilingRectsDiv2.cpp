#line 2 "PilingRectsDiv2.cpp"
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
const int INF = 1 << 28;

class PilingRectsDiv2 {
	public:
	int getmax(vector <int> X, vector <int> Y, int limit) {
		int dp[51][201][201];
		fill(dp[0][0], dp[51][0], -1);
		dp[0][0][0] = 0;
		for(int i=0;i<X.size();i++){
			for(int j=0;j<=200;j++){
				for(int k=0;k<=200;k++){
					if(dp[i][j][k] == -1) continue;
					dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
					int nx, ny;
					if(j == 0){
						nx = X[i];
						ny = Y[i];
						dp[i+1][nx][ny] = max(dp[i+1][nx][ny], dp[i][j][k] + 1);
					}else{
						nx = min(j, X[i]);
						ny = min(k, Y[i]);
						dp[i+1][nx][ny] = max(dp[i+1][nx][ny], dp[i][j][k] + 1);
						nx = min(j, Y[i]);
						ny = min(k, X[i]);
						dp[i+1][nx][ny] = max(dp[i+1][nx][ny], dp[i][j][k] + 1);
					}
				}
			}
		}
		int res = -1;
		for(int i=0;i<=200;i++){
			for(int j=0;j<=200;j++){
				if(i * j >= limit){
					res = max(res, dp[X.size()][i][j]);
				}
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
	void test_case_0() { int Arr0[] = {1,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(0, Arg3, getmax(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {4,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; int Arg3 = 2; verify_case(1, Arg3, getmax(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9999; int Arg3 = -1; verify_case(2, Arg3, getmax(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30; int Arg3 = 1; verify_case(3, Arg3, getmax(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {3,6,5,8,2,9,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14,6,13,8,15,6,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 27; int Arg3 = 4; verify_case(4, Arg3, getmax(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5345; int Arg3 = 24; verify_case(5, Arg3, getmax(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  PilingRectsDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
