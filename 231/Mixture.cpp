#line 2 "Mixture.cpp"
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

#define REP(i,n) for(int (i)=0;(i)<(int)(n);++(i))

const double EPS = 1e-10;

int STATUS = 0; // 1: unbounded, 2: no solution
typedef double Num;
typedef vector<Num> Vec;
typedef vector<Vec> Mat;

/**
 * Maximize: c * x
 * A * x <= b
 * x     >= 0
 */
Num simplex(const Mat& A, const Vec& b, const Vec& c) {
  const int M = A.size(), N = A[0].size();
  Mat D(M + 1, Vec(N + 1));
  vector<int> id(N + M + 1);
  for(int i = 0; i <= N + M; ++i) id[i] = i;
  REP(i, M) {
    REP(j, N) D[i][j] = -A[i][j];
    D[i][N] = b[i];
  }
  REP(j, N) D[M][j] = c[j];
  for(;;) {
    int r = M, s = N + M;
    REP(i, M) if(D[i][N] < -EPS && id[N + r] > id[N + i]) r = i;
    REP(j, N) if(D[M][j] > EPS && id[s] > id[j]) s = j;
    if(r == M && s == N + M) break;
    if(id[N + r] < id[s]) {
      s = N + M;
      REP(j, N) if(D[r][j] > EPS && id[s] > id[j]) s = j;
    }else {
      r = M;
      REP(i, M) if(D[i][s] < -EPS && id[N + r] > id[N + i]) r = i;
    }
    if(r == M) return STATUS = 1;
    if(s == N + M) return STATUS = 2;
    swap(id[s], id[N + r]);
    D[r][s] = 1.0 / D[r][s];
    for(int j = 0; j <= N; ++j) if(j != s) D[r][j] *= -D[r][s];
    for(int i = 0; i <= M; ++i) {
      if(i != r && abs(D[i][s]) > EPS) {
        for(int j = 0; j <= N; ++j) {
          if(j != s) D[i][j] += D[r][j] * D[i][s];
        }
        D[i][s] *= D[r][s];
      }
    }
  }
  return D[M][N];
}

class Mixture {
public:
  double mix(vector <int> mixture, vector <string> available) {
    STATUS = 0;

    const int M = mixture.size();
    const int N = available.size();

    Mat A(M * 2, Vec(N));
    Vec b(M * 2);
    Vec c(N);
    REP(i, M) {
      b[i] = mixture[i];
      b[M + i] = -mixture[i];
    }
    REP(j, N) {
      istringstream ss(available[j]);
      REP(i, M) {
        int in;
        ss >> in;
        A[i][j] = in;
        A[M + i][j] = -in;
      }
      ss >> c[j];
      c[j] = -c[j];
    }

    double res = simplex(A, b, c);
    if(STATUS == 2) return -1.0;
    return -res;
  }

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 0 0 1","0 1 0 2","0 0 1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 14.0; verify_case(0, Arg2, mix(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 0 0 1","0 1 0 2","0 0 1 3","2 2 2 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 10.0; verify_case(1, Arg2, mix(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10 9 9 9 9 9 9 9 9 10 0",
                                                                                                                                              "0 10 9 9 9 9 9 9 9 0 0",
                                                                                                                                              "0 0 10 9 9 9 9 9 9 0 0",
                                                                                                                                              "0 0 0 10 9 9 9 9 9 0 0",
                                                                                                                                              "0 0 0 0 10 9 9 9 9 0 0",
                                                                                                                                              "0 0 0 0 0 10 9 9 9 0 0",
                                                                                                                                              "0 0 0 0 0 0 10 9 9 0 0",
                                                                                                                                              "0 0 0 0 0 0 0 10 9 0 0",
                                                                                                                                              "0 0 0 0 0 0 0 0 10 1 0",
                                                                                                                                              "0 0 0 0 0 0 0 0 0 10 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(2, Arg2, mix(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7,7,8,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"9 0 4 8 4",
                                                                                                                                   "8 8 9 0 1",
                                                                                                                                   "0 10 3 10 7",
                                                                                                                                   "10 2 2 0 1",
                                                                                                                                   "8 9 10 2 6",
                                                                                                                                   "1 2 5 8 8",
                                                                                                                                   "4 7 8 9 6",
                                                                                                                                   "2 10 6 8 10",
                                                                                                                                   "6 3 9 7 1",
                                                                                                                                   "3 6 9 9 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.5855425945563804; verify_case(3, Arg2, mix(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Mixture ___test;
  ___test.run_test(-1);
}
// END CUT HERE
