#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cassert>

#define debug(x)  cout<<#x<<" = "<<x<<endl;
#define debugs(arr,num) cout<<#arr<<" = ";for(int zz=0;zz<num;zz++)cout<<arr[zz]<<" ";cout<<endl;

using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            vector<vector<bool> > dp(p.size() + 1, vector<bool>(s.size() + 1, false));  
            dp[0][0] = true;

            for (int m = 1; m <= p.size(); ++m) {
                if (p[m - 1] == '*') {
                    for (int n = 0; n <= s.size(); ++n) {
                        if (dp[m - 2][n] == true || dp[m - 1][n] == true) {
                            dp[m][n] = true;
                        }
                        if (n > 0 && dp[m][n - 1] == true && (p[m - 2] == s[n - 1] || p[m - 2] == '.')) {
                            dp[m][n] = true;
                        }
                    }
                }
                else {
                    for (int n = 1; n <= s.size(); ++n) {
                        if (dp[m - 1][n - 1] == true && (p[m - 1] == '.' || p[m - 1] == s[n - 1])) {
                            dp[m][n] = true;
                        }
                    }
                }
            }
            return dp[p.size()][s.size()];
        }
};

int main() {
    Solution sol;
    assert(sol.isMatch("aa","a")   == false);
    assert(sol.isMatch("aa","aa")  == true);
    assert(sol.isMatch("aaa","aa") == false);
    assert(sol.isMatch("aa", "a*") == true);
    assert(sol.isMatch("aa", ".*") == true);
    assert(sol.isMatch("aaa", ".*") == true);
    assert(sol.isMatch("ab", ".*") == true);
    assert(sol.isMatch("aab", "ac*a*b") == true);
    assert(sol.isMatch("aab", "c*a*b") == true);
    assert(sol.isMatch("ab", ".*c") == false);
    assert(sol.isMatch("aaba", "ab*a*c*a") == false);
    return 0;
}
