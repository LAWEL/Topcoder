#line 2 "Decipherability.cpp"
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

class Decipherability {
	public:
	string check(string s, int K) {
    vector<pair<int, int> > vec;
    int size = s.size();
    vec.reserve(size*size);
    for(int i = 0; i < size; ++i){
      for(int j = i + 1; j < size; ++j){
        if(s[i] == s[j]){
          vec.push_back(make_pair(i, j));
        }
      }
    }
    int dp[50][50][50];
    memset(dp, 0, sizeof(dp));
    int size2 = vec.size();
    for(int i = 0; i < size2; ++i){
      {
        int& tmp = dp[vec[i].first][vec[i].second][vec[i].second];
        tmp = max(tmp, 1);
      }
      for(int j = 0; j < size; ++j){
        for(int k = j; k < size; ++k){
          for(int l = k; l < size; ++l){
            if(dp[j][k][l] == 0) continue;
            //cout << j << ", " << k << ", " << l << endl;
            if(j < vec[i].first && vec[i].first < k &&
               l < vec[i].second){
              int& tmp = dp[vec[i].first][k][vec[i].second];
              tmp = max(tmp, dp[j][k][l] + 1);
            }
          }
        }
      }
    }
    const int INF = 1000000;
    int ans = INF;
    for(int j = 0; j < size; ++j){
      for(int k = 0; k < size; ++k){
        for(int l = 0; l < size; ++l){
          if(dp[j][k][l] == 0) continue;
          ans = min(ans, dp[j][k][l]);
          //ans = max(ans, dp[j][k][l]);
        }
      }
    }
    bool res = false;
    if(ans == INF) res = true;
    if((int)s.size() == K) res = true;
    //if((int)s.size() - K > ans) res = true;
    if(K < ans) res = false;
    cout << ans << ", " << s.size() - K << " or " << ans << ", " << K << endl;
    return !res ? "Uncertain" : "Certain";
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "snuke"; int Arg1 = 2; string Arg2 = "Certain"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aba"; int Arg1 = 1; string Arg2 = "Certain"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "aba"; int Arg1 = 2; string Arg2 = "Uncertain"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcdabcd"; int Arg1 = 3; string Arg2 = "Certain"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "koukyoukoukokukikou"; int Arg1 = 2; string Arg2 = "Uncertain"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "wolfsothe"; int Arg1 = 8; string Arg2 = "Uncertain"; verify_case(5, Arg2, check(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "aa"; int Arg1 = 2; string Arg2 = "Certain"; verify_case(6, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Decipherability ___test;
  ___test.run_test(-1);
}
// END CUT HERE
