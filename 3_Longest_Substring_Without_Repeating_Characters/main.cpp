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
    int lengthOfLongestSubstring(string s) {
        vector<int> alpha(256,0);
        int head=0,tail=0,len=(int)s.size();
        string lst="";
        while (head<len) {
            if (alpha[s[head]]==0) {
                alpha[s[head]]=1;
                ++head;
            }
            else {
                if (head-tail > lst.size()) {
                    lst=string(s,tail,head-tail);
                }
                //debug(lst)
                while(alpha[s[head]]==1 && tail<head) {
                    alpha[s[tail]]=0;
                    ++tail;
                }
            }
            if (head==len) {
                if (head-tail > lst.size()) {
                    lst=string(s,tail,head-tail);
                }
                break;
            }
        }
        //debug(lst);
        return lst.size();
    }
};

int main() {
    Solution sol;
    int len=sol.lengthOfLongestSubstring("aaaaa#@*)!%*#@!)&%)@!#(^$*\"\"\"\"dazcgrf");
    debug(len)
    return 0;
}
