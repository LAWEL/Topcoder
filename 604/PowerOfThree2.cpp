#line 2 "PowerOfThree.cpp"
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

class PowerOfThree {
	public:
	bool used[1000];
	vector<lli> num;
	bool check(lli x){
		if(x == 0) return true;
		vector<lli>::iterator ite = lower_bound(num.begin(), num.end(), x);
		lli ind = ite - num.begin();
		lli tmp = *ite;
		if(!used[ind]){
			used[ind] = true;
			if(tmp == x){
				return true;
			}else{
				bool res = check(abs(x - tmp));
				if(res) return res;
			}
			used[ind] = false;
		}
		ite = upper_bound(num.begin(), num.end(), x);
		ite--;
		ind = ite - num.begin();
		tmp = *ite;
		if(!used[ind]){
			used[ind] = true;
			if(tmp == x){
				return true;
			}else{
				bool res = check(abs(x - tmp));
				if(res) return res;
			}
			used[ind] = false;
		}
		return false;
	}
	string ableToGet(lli x, lli y) {
		if(x == 0 && y == 0) return "Possible";
		fill(used, used+1000, false);
		num.clear();
		num.push_back(1);
		for(int i=0;;i++){
			lli tmp = num.back();
			num.push_back(tmp * 3);
			if(num.back() > 1000000000LL) break;
		}
		if(!check(abs(x))){
			return "Impossible";		
		}
		if(!check(abs(y))){
			return "Impossible";		
		}
		bool f = false;
		for(int i=0;i<1000;i++){
			if(used[i] && f) return "Impossible";
			if(!used[i]) f = true;
		}
		return "Possible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 4; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -6890; int Arg1 = 18252; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1000000000; int Arg1 = -1000000000; string Arg2 = "Impossible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 0; int Arg1 = 0; string Arg2 = "Possible"; verify_case(7, Arg2, ableToGet(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  PowerOfThree ___test;
  ___test.run_test(-1);
}
// END CUT HERE
