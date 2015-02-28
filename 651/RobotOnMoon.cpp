#line 2 "RobotOnMoon.cpp"
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

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

class RobotOnMoon {
	public:
	int longestSafeCommand(vector <string> b) {
    int H = b.size();
    int W = b[0].size();
    int sy, sx;
    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(b[i][j] == 'S'){
          sy = i;
          sx = j;
        }
      }
    }
    for(int j = 0; j < W; ++j) {
      if(b[sy][j] == '#') return -1;
    }
    for(int i = 0; i < H; ++i) {
      if(b[i][sx] == '#') return -1;
    }
    return H + W - 2;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, longestSafeCommand(Arg0)); }
	void test_case_1() { string Arr0[] = {"S......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, longestSafeCommand(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, longestSafeCommand(Arg0)); }
	void test_case_3() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, longestSafeCommand(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  RobotOnMoon ___test;
  ___test.run_test(-1);
}
// END CUT HERE
