#line 2 "ShadowSculpture.cpp"
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
bool use[10][10][10];
bool vis[10][10][10];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int N;

class ShadowSculpture {
	public:
  void dfs(int x, int y, int z) {
    vis[x][y][z] = true;
    for(int i = 0; i < 6; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if(nx < 0 || nx >= N) continue;
      if(ny < 0 || ny >= N) continue;
      if(nz < 0 || nz >= N) continue;
      if(!use[nx][ny][nz]) continue;
      if(vis[nx][ny][nz]) continue;
      dfs(nx, ny, nz);
    }
  }
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
    N = XY.size();
    fill(use[0][0], use[10][0], true);
    bool f = false;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(XY[i][j] == 'N') {
          for(int k = 0; k < N; ++k) {
            use[i][j][k] = false;
          }
        } else f = true;
      }
    }
    for(int j = 0; j < N; ++j) {
      for(int k = 0; k < N; ++k) {
        if(YZ[j][k] == 'N') {
          for(int i = 0; i < N; ++i) {
            use[i][j][k] = false;
          }
        } else f = true;
      }
    }
    for(int k = 0; k < N; ++k) {
      for(int i = 0; i < N; ++i) {
        if(ZX[k][i] == 'N') {
          for(int j = 0; j < N; ++j) {
            use[i][j][k] = false;
          }
        } else f = true;
      }
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        for(int k = 0; k < N; ++k) {
          if(!use[i][j][k]) {
            cnt++;
          }
        }
      }
    }
    if(!f) return "Possible";
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        for(int k = 0; k < N; ++k) {
          if(use[i][j][k]) {
            memset(vis, 0, sizeof(vis));
            dfs(i, j, k);
            bool f2 = true;
            for(int p = 0; p < N; ++p) {
              for(int q = 0; q < N; ++q) {
                if(XY[p][q] == 'Y') {
                  bool f3 = false;
                  for(int r = 0; r < N; ++r) {
                    if(vis[p][q][r]) {
                      f3 = true;
                    }
                  }
                  f2 &= f3;
                }
                if(YZ[p][q] == 'Y') {
                  bool f3 = false;
                  for(int r = 0; r < N; ++r) {
                    if(vis[r][p][q]) {
                      f3 = true;
                    }
                  }
                  f2 &= f3;
                }
                if(ZX[p][q] == 'Y') {
                  bool f3 = false;
                  for(int r = 0; r < N; ++r) {
                    if(vis[q][r][p]) {
                      f3 = true;
                    }
                  }
                  f2 &= f3;
                }
              }
            }
            if(f2) return "Possible";
          }
        }
      }
    }
    return "Impossible";
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  ShadowSculpture ___test;
  ___test.run_test(-1);
}
// END CUT HERE
