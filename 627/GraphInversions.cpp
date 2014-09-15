#line 2 "GraphInversions.cpp"
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
typedef pair<int, int> P;

const double EPS = 1e-8;

class GraphInversions {
	public:
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
		int res = 1000000;
    vector<P> G[1000];
    for(int i=0;i<A.size();i++){
      G[A[i]].push_back(make_pair(B[i], V[i]));
      G[B[i]].push_back(make_pair(A[i], V[i]));
    }
    int root = -1;
    for(int i=0;i<A.size();i++){
      if(G[i].size() == 1){
        if(root != -1){
          return -1;
        }
        root = i;
      }
    }
    if(root == -1){
      int cnt = 0;
      vector<P> vec;
      for(int i=0;i<A.size();i++){
        vec.push_back(make_pair(A[i], V[i]));
      }
      sort(vec.begin(), vec.end());
      for(int i=0;i+2<A.size();i++){
        if(V[i] > V[i+1]) cnt++;
      }
      for(int i=0;i<A.size();i++){
        res = min(res, cnt);
        if(V[i] > V[(i+1)%A.size()]){
          cnt--;
        }
        if(V[(i+A.size()-1)%A.size()] > V[(i+A.size())%A.size()]){
          cnt++;
        }
      }
      res = min(res, cnt);
    }else{
      {
        int cnt = 0;
        int pos = G[root][0].first;
        int prev = G[root][0].second;
        for(int i=1;i+1<A.size();i++){
          if(prev > G[pos][0].second){
            cnt++;
          }
          pos = G[pos][0].first;
          prev = G[pos][0].second;
        }
        res = min(res, min(cnt, (int)A.size() - 1 - cnt));
      }
      {
        int cnt = 0;
        int pos = G[root][G[root].size()-1].first;
        int prev = G[root][G[root].size()-1].second;
        for(int i=1;i+1<A.size();i++){
          if(prev > G[pos][G[pos].size()-1].second){
            cnt++;
          }
          pos = G[pos][G[pos].size()-1].first;
          prev = G[pos][G[pos].size()-1].second;
        }
        res = min(res, min(cnt, (int)A.size() - 1 - cnt));
      }
    }
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,50,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(0, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {60,40,50,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; verify_case(1, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,2,5,3,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = -1; verify_case(3, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {5,7,7,5,5,7,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,2,0,1,4,7,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,10,5,30,22,10,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 3; verify_case(4, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  GraphInversions ___test;
  ___test.run_test(-1);
}
// END CUT HERE
