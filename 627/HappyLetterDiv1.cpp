#line 2 "HappyLetterDiv1.cpp"
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

class HappyLetterDiv1 {
	public:
  bool calc(vector<int> vec, int rem){
    if(rem % 2 == 1){
      return false;
    }
    while(rem > 0){
      // for(int i=0;i<vec.size();i++){
      //   cout << vec[i] << ' ';
      // }
      // cout << endl;
      // cout << "rem = " << rem << endl;
      vector<int> tmp = vec;
      vec.clear();
      for(int i=0;i<tmp.size();i++){
        if(tmp[i] > 0) vec.push_back(tmp[i]);
      }
      sort(vec.begin(), vec.end());
      for(int i=vec.size()-1;i>=0;i--){
        if(i == 0){
          return false;
        }
        vec[i] -= 1;
        vec[0] -= 1;
        rem -= 2;
        break;
      }
    }
    return true;
  }
	string getHappyLetters(string let) {
    int sum = let.size();
    int dat[26];
    fill(dat, dat+26, 0);
    for(int i=0;i<let.size();i++){
      dat[let[i]-'a']++;
    }
    vector<int> vec;
    vector<int> vec2;
    for(int i=0;i<26;i++){
      if(dat[i] == 0) continue;
      vec.push_back(dat[i]);
      vec2.push_back(i);
    }
    string res;
    for(int i=0;i<vec.size();i++){
      for(int j=1;j<=vec[i];j++){
        vec[i] -= j;
        //       cout << (char)('a' + vec2[i]) << ", j = " << j << endl;
        if(calc(vec, sum - j)){
          res.push_back((char)('a' + vec2[i]));
          vec[i] += j;
          break;
        }
        vec[i] += j;
      }
    }
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
	void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
	void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  HappyLetterDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
