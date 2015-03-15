#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

#define debug(x)  cout<<#x<<" = "<<x<<endl;
#define debugs(arr,num) cout<<#arr<<" = ";for(int zz=0;zz<num;zz++)cout<<arr[zz]<<" ";cout<<endl;

using namespace std;

class Solution {
public:
    char* pre_process(string s) {
        char* p = new char[s.size()*2+3];
        p[0]='$';
        p[1]='#';
        for (int i=1;i<=s.size();++i) {
            p[i*2]=s[i-1];
            p[i*2+1]='#';
        }
        p[s.size()*2+2]='\0';
        return p;
    }
    string longestPalindrome(string s) {
        char* st = pre_process(s);
        //debugs(st, s.size()*2+2);
        int mx = 0, id = 0;
        int p[2020];
        memset(p, 0, sizeof(p));
        for (int i = 1; st[i] != '\0'; ++i) {
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
            while (st[i + p[i]] == st[i - p[i]]) ++p[i];
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        //debugs(p, s.size()*2+2);
        int max=0,max_pos;
        for (int i = 1; st[i] != '\0'; i++) {
            if (p[i]>max) {
                max = p[i];
                max_pos = i;
            }
        }
        string lst(s,max_pos/2-max/2,max-1);
        return lst;
    }
};

int main() {
    Solution sol;
    string st;
    st = sol.longestPalindrome("");
    debug(st);
    return 0;
}
