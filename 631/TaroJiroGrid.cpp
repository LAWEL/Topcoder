#line 2 "TaroJiroGrid.cpp"
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

class TaroJiroGrid {
public:
  void func(int y, char c, vector<string>&grid) {
    for(int j=0;j<grid[y].size();j++){
      grid[y][j] = c;
    }
  }

  bool check(vector<string>&grid){
    int cnt[50][50];
    for(int i=0;i<50;i++){
      for(int j=0;j<50;j++){
        if(i == 0){
          cnt[i][j] = 1;
        } else {
          cnt[i][j] = 0;
        }
      }
    }
    for(int i=1;i<grid.size();i++){
      for(int j=0;j<grid[i].size();j++){
        if(grid[i-1][j] == grid[i][j]) {
          cnt[i][j] = cnt[i-1][j] + 1;
        } else {
          cnt[i][j] = 1;
        }
      }
    }
    bool bad = false;
    for(int i=0;i<grid.size();i++){
      for(int j=0;j<grid[i].size();j++){
        if(cnt[i][j] > grid.size() / 2) {
          bad = true;
        }
      }
    }
    return !bad;
  }

	int getNumber(vector <string> grid) {
    int cnt[50][50];
    for(int i=0;i<50;i++){
      for(int j=0;j<50;j++){
        if(i == 0){
          cnt[i][j] = 1;
        } else {
          cnt[i][j] = 0;
        }
      }
    }
    for(int i=1;i<grid.size();i++){
      for(int j=0;j<grid[i].size();j++){
        if(grid[i-1][j] == grid[i][j]) {
          cnt[i][j] = cnt[i-1][j] + 1;
        } else {
          cnt[i][j] = 1;
        }
      }
    }
    bool bad = false;
    for(int i=1;i<grid.size();i++){
      for(int j=0;j<grid[i].size();j++){
        if(cnt[i][j] > grid.size() / 2) {
          bad = true;
        }
      }
    }
    if(!bad) {
      return 0;
    }
    for(int i=grid.size()-2;i>=0;--i) {
      for(int j=0;j<grid[i].size();j++){
        if(grid[i+1][j] == grid[i][j]) {
          cnt[i][j] = cnt[i+1][j];
        }
      }
    }
    int y1 = 0;
    int y2 = 0;
    char c = ' ';
    for(int j=0;j<grid.size();j++){
      for(int i=0;i<grid.size();i++){
        if(cnt[i][j] > grid.size() / 2) {
          c = grid[i][j];
          y1 = i;
          while(cnt[i+1][j] == cnt[i][j]) {
            i++;
          }
          y2 = i + 1;
        }
      }
    }
    for(int i=y1;i<y2;i++){
      string tmp = grid[i];
      func(i, (c == 'W' ? 'B' : 'W'), grid);
      if(check(grid)) {
        return 1;
      }
      grid[i] = tmp;
    }
    return 2;
	}

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"WB",
                                        "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"WB",
                                        "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"WB",
                                        "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"WBBW",
                                        "WBWB",
                                        "WWBB",
                                        "BWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBWBB",
                                        "BBWBBW",
                                        "WWBWBW",
                                        "BWWBBB",
                                        "WBWBBW",
                                        "WWWBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  TaroJiroGrid ___test;
  ___test.run_test(-1);
}
// END CUT HERE
