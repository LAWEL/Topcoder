#line 2 "Family.cpp"
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

class Family {
	public:
	vector<int> G[100];
	int V;
	int color[100];

	bool dfs(int v, int c){
		color[v] = c;
		for(int i=0;i<G[v].size();i++){
			if(color[G[v][i]] == c) return false;
			if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
		}
		return true;
	}

	bool solve(){
		for(int i=0;i<V;i++){
			if(color[i] == 0){
				if(!dfs(i, 1)){
					return false;
				}
			}
		}
		return true;
	}

	string isFamily(vector <int> pa1, vector <int> pa2) {
		for(int i=0;i<100;i++){
			color[i] = 0;
			G[i].clear();
		}
		V = pa1.size();
		for(int i=0;i<pa1.size();i++){
			if(pa1[i] != -1 && pa2[i] != -1){
				G[pa1[i]].push_back(pa2[i]);
				G[pa2[i]].push_back(pa1[i]);
				//cout << pa1[i] << ' ' << pa2[i] << endl;
			}
		}
		return solve() ? "Possible" : "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,-1,-1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,-1,0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, isFamily(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Family ___test;
  ___test.run_test(-1);
}
// END CUT HERE
