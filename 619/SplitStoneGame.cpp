#line 2 "SplitStoneGame.cpp"
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

class SplitStoneGame {
	public:
	int memo[51][51];
	int calc(int a, int b, int c){
		if(memo[a][b] != -1){
			return memo[a][b];
		}
		int res = c;
		if(a + b > 2 && b > 0){
			b--;
			int tmp;
			if(b >= 2){
				tmp = calc(a, b, 1 - c);
				if(tmp == 1 - c){
					res = 1 - c;
				}
			}
			if(b >= 1 && a >= 1){
				tmp = calc(a - 1, b + 1, 1 - c);
				if(tmp == 1 - c){
					res = 1 - c;
				}
			}
			if(a >= 2){
				tmp = calc(a - 2, b + 2, 1 - c);
				if(tmp == 1 - c){
					res = 1 - c;
				}
			}
		}
		memo[a][b] = res;
		return res;
	}
	string winOrLose(vector <int> num) {
		int a = 0, b = 0;
		for(int i=0;i<51;i++){
			for(int j=0;j<51;j++){
				memo[i][j] = -1;
			}
		}
		for(int i=0;i<num.size();i++){
			if(num[i] == 1) a++;
			else b++;
		}
		string res;
		return calc(a, b, 0) ? "WIN" : "LOSE";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(0, Arg1, winOrLose(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(1, Arg1, winOrLose(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN"; verify_case(2, Arg1, winOrLose(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN"; verify_case(3, Arg1, winOrLose(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(4, Arg1, winOrLose(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SplitStoneGame ___test;
  ___test.run_test(-1);
}
// END CUT HERE
