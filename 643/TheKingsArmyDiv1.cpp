#line 2 "TheKingsArmyDiv1.cpp"
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

class TheKingsArmyDiv1 {
	public:
	int getNumber(vector <string> s) {
    int cnt[4];
    memset(cnt, 0, sizeof(cnt));
    const auto size = s[0].size();
    for(int i = 0; i < size; ++i){
      if(s[0][i] == 'H' && s[1][i] == 'H'){
        cnt[0]++;
      }else if(s[0][i] == 'S' && s[1][i] == 'S'){
        cnt[1]++;
      }else if(s[0][i] == 'H' && s[1][i] == 'S'){
        cnt[2]++;
      }else if(s[0][i] == 'S' && s[1][i] == 'H'){
        cnt[3]++;
      }
    }
    int res = -1;
    if(cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] != 0){
      res = 1;
    }
    else if(cnt[0] == 0 && cnt[1] == 0 && cnt[2] != 0 && cnt[3] == 0){
      res = 1;
    }
    else if(cnt[0] == 0 && cnt[1] == 0 && cnt[2] != 0 && cnt[3] != 0){
      res = min(cnt[2], cnt[3]) + 1;
    }
    else if(cnt[0] == 0 && cnt[1] != 0 && cnt[2] == 0 && cnt[3] == 0){
      res = -1;
    }
    else if(cnt[0] == 0 && cnt[1] != 0 && cnt[2] == 0 && cnt[3] != 0){
      res = cnt[1] + 1;
    }
    else if(cnt[0] == 0 && cnt[1] != 0 && cnt[2] != 0 && cnt[3] == 0){
      res = cnt[1] + 1;
    }
    else if(cnt[0] == 0 && cnt[1] != 0 && cnt[2] != 0 && cnt[3] != 0){
      res = cnt[1] + min(cnt[2], cnt[3]) + 1;
    }
    else if(cnt[0] != 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0){
      res = 0;
    }
    else if(cnt[0] != 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] != 0){
      res = 1;
    }
    else if(cnt[0] != 0 && cnt[1] == 0 && cnt[2] != 0 && cnt[3] == 0){
      res = 1;
    }
    else if(cnt[0] != 0 && cnt[1] == 0 && cnt[2] != 0 && cnt[3] != 0){
      res = min(cnt[2], cnt[3]) + 1;
    }
    else if(cnt[0] != 0 && cnt[1] != 0 && cnt[2] == 0 && cnt[3] == 0){
      res = cnt[1];
    }
    else if(cnt[0] != 0 && cnt[1] != 0 && cnt[2] == 0 && cnt[3] != 0){
      res = cnt[1] + 1;
    }
    else if(cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 && cnt[3] == 0){
      res = cnt[1] + 1;
    }
    else if(cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 && cnt[3] != 0){
      res = cnt[1] + min(cnt[2], cnt[3]) + 1;
    }
    return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"HSH",
 "SHS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"HH",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"HHHHH",
 "HSHSH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"S",
 "S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"HSHHSHSHSHHHSHSHSH",
 "SSSSHSSHSHSHHSSSSH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { string Arr0[] = {"HS",
 "HS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  TheKingsArmyDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
