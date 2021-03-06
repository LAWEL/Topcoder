#line 2 "GreaterGame.cpp"
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

class GreaterGame {
public:
	double calc(vector <int> hand, vector <int> sothe) {
    int N = hand.size();
    bool used2[200];
    fill(used2, used2+200, false);
    for(int i = 0; i < N; i++){
      used2[hand[i]] = true;
      if(sothe[i] != -1) {
        used2[sothe[i]] = true;
      }
    }
    vector<int> hand2;
    for(int i = 1; i <= N * 2; ++i) {
      if(!used2[i]) hand2.push_back(i);
    }
    double res = 0;
    bool used[50];
    fill(used, used+50, false);
    sort(hand.begin(), hand.end());
    sort(sothe.begin(), sothe.end());
    for(int i = N - 1; i >= 0; --i) {
      if(sothe[i] == -1) break;
      bool f = false;
      int prev = -1;
      for(int j = 0; j < N; ++j) {
        if(used[j]) continue;
        if(prev == -1) prev = j;
        //cout << hand[j] << ' ' << sothe[i] << endl;
        if(hand[j] > sothe[i]) {
          used[j] = true;
          f = true;
          res += 1;
          break;
        }
      }
      if(prev == -1) break;
      if(!f) {
        //cout << "prev = " << prev << endl;
        used[prev] = true;
      }
    }
    vector<int> tmp = hand;
    hand.resize(0);
    for(int i = 0; i < N;i++){
      if(!used[i]) hand.push_back(tmp[i]);
    }
    if(hand.size() == 0) return res;

    long long d[51];
    d[0] = 1;
    for(int i = 1; i < 51; ++i) {
      d[i] = d[i-1] * i;
    }
    long long cnt = 0;
    for(int i = 0; i < hand.size(); ++i) {
      int cnt2 = 0;
      for(int j = 0; j < hand2.size(); ++j) {
        //cout << h[i] << ' ' << h2[j] << endl;
        if(hand[i] > hand2[j]) cnt2++;
      }
      cnt += cnt2;
    }
    return res + (double)cnt / hand.size();
    //cout << res << ' ' << cnt << ' ' << h.size() << endl;
    return res + (double)cnt / tmp[hand.size()];
	}

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,-1,4,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,12,17,14,20,8,16,7,2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  GreaterGame ___test;
  ___test.run_test(-1);
}
// END CUT HERE
