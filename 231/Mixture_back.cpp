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

const double EPS = 1e-10;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

int STATUS = 0; // 1: unbounded, 2: no solution

void print(const Mat&);

int N, M;

void pivot(Mat& A, const int y, const int x, vector<int>& id) {
  double tmp = A[y][x];
  for(int i = 0; i < N + 1; ++i) A[y][x] /= tmp;
  for(int i = 0; i < M + 1; ++i) {
    if(i == y) continue;
    tmp = A[i][x];
    for(int j = 0; j < N + 1; ++j) A[i][j] -= tmp * A[y][j];
    A[i][x] = 0.0;
  }
  id[y] = x;
}

double simplex(const Mat& S) {
  vector<int> id(M);
   print(S);
  // full rank

   int oldM = M;
   Mat T(M + 1, Vec(N + M + 1));
  for(int i = 0; i < oldM; ++i) {
    for(int j = 0;j < N + 1; ++j) {
      T[i][j] = S[i][j];
    }
  }
  for(int i = 0;i < M; ++i) {
    int tmp = -1;
    for(int j = 0;j < N; ++j) {
      if(abs(T[i][j]) > EPS && (tmp == -1 || abs(T[i][j]) > abs(T[i][tmp]))) tmp = j;
    }
    if(tmp != -1) {
      pivot(T, i, tmp, id);
    } else {
      --M;
      for(int j = 0; j < N + 1; ++j) {
        swap(T[i][j], T[M][j]);
      }
    }
  }
   print(T);
  // prepare first step
  for(int i = 0; i < M; ++i) T[i][M+N] = T[i][N];
  for(int i = 0; i < M; ++i) {
    if(T[i][M+N] < 0.0) {
      for(int j = 0; j < M + N + 1; ++j) {
        T[i][j] = -T[i][j];
      }
    }
  }
  for(int i = 0; i < M; ++i) {
    for(int j = 0; j < M; ++j) {
      T[i][N + j] = ((i == j) ? 1 : 0);
    }
  }
  for(int i = 0; i < M + N + 1; ++i) T[M][i] = 0.0;
  for(int i = 0; i < M; ++i) T[M][N + i] = 1.0;
  N += M;
  for(int i = 0; i < M; ++i) id[i] = N - M + i;
  for(int i = 0; i < M; ++i) pivot(T, i, id[i], id);

   print(T);
  //first step
  while(1) {
    int j;
    for(j = 0; j < N; ++j) {
      if(T[M][j] < -EPS) break;
    }
    if(j == N) break;
    int tmp = -1;
    for(int i = 0; i < M; ++i) {
      if(T[i][j] > EPS && (tmp == -1 || T[i][N] / T[i][j] < T[tmp][N] / T[tmp][j] - EPS)) {
        tmp = i;
      }
    }
    if(tmp == -1) return STATUS = 1;
    pivot(T, tmp, j, id);
  }
  print(T);
  vector<bool> used(N + M + 1, false);
  //prepare second step
  if(T[M][N] < -EPS) return STATUS = 2;
  for(int i = 0; i < M; ++i) {
    if(id[i] >= N - M) {
      int j;
      for(j = 0; j < N; ++j) {
        used[j] = false;
      }
      for(j = 0; j < M; ++j) {
        used[id[j]];
      }
      for(j = 0; ; ++j) {
        if(!used[j]) break;
      }
      pivot(T, i, j, id);
    }
  }
  N -= M;
  for(int i = 0; i < M; ++i) {
    T[i][N] = T[i][M + N];
  }
  for(int i = 0; i < N + 1; ++i) {
    T[M][i] = S[oldM][i];
  }
  for(int i = 0; i < M; ++i) {
    pivot(T, i, id[i], id);
  }
  print(T);
  //second step
  while(1) {
    int j;
    for(j = 0; j < N; ++j) {
      if(T[M][j] < -EPS) break;
    }
    if(j == N) break;
    int tmp = -1;
    for(int i = 0; i < M; ++i) {
      if(T[i][j] > EPS && (tmp == -1 || T[i][N] / T[i][j] < T[tmp][N] / T[tmp][j] -EPS)) {
        tmp = i;
      }
    }
    if(tmp == -1) return STATUS = 1;
    pivot(T, tmp, j, id);
  }
  //print(T);
  return -T[M][N];
}

/**
 * Maximize: c * x
 * Subject to:
 * A * x <= b
 * x >= 0
 */
double simplex(const Mat& A, const Vec& b, const Vec& c) {
  const int m = A.size();
  const int n = c.size();
  Mat S(m + 1, Vec(n + 1));
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      S[i][j] = A[i][j];
    }
    S[i][n] = b[i];
  }
  for(int i = 0; i < n; ++i) S[m][i] = c[i];
  return simplex(S);
}

void print(const Mat& A) {
  const int m = A.size();
  const int n = A[0].size();
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      if(!(A[i][j] < 0.0)) printf(" ");
      printf("%.3f", A[i][j]);
    }
    puts("");
  }
  puts("");
}

class Mixture {
	public:
	double mix(vector <int> mixture, vector <string> available) {
    STATUS = 0;
    M = mixture.size();
    N = available.size();
    Mat A(M + 1, Vec(N + 1));
    for(int i = 0; i < M; ++i) {
      A[i][N] = mixture[i];
    }
    for(int j = 0; j < N; ++j) {
      istringstream is(available[j]);
      for(int i = 0; i < M + 1; ++i) {
        is >> A[i][j];
      }
    }
    double res = simplex(A);
    printf("STATUS = %d\n", STATUS);
    if(STATUS == 2) return -1.0;
    return res;
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
  ___test.run_test(1);
}
// END CUT HERE
