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
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int result_pos = 0, len = s.size();
        char* result = new char[len + 1];
        int x, mid;
        for (int row = 1; row <= numRows; ++row) {
            x = row;
            while (x <= len) {
                result[result_pos++] = s[x - 1];
                mid = x + 2 * numRows - 2 - 2 * (row - 1);
                if (row != 1 && row != numRows && mid <= len) {
                    result[result_pos++] = s[mid - 1];
                }
                x = x + 2 * numRows - 2;
            }
        }
        result[result_pos++] = '\0';
        return string(result);
    }
};

int main() {
    Solution sol;
    string s = sol.convert("ABCDE", 1);
    cout << s << endl;
    return 0;
}
