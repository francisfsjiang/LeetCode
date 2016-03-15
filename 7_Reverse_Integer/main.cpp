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
    int reverse(int x) {
        bool sign = true;
        long long result = 0;
        if (x == INT32_MIN) {
            return 0;
        }
        else if (x < 0) {
            sign = false;
            x = - x;
        }
        while (x > 0) {
            result *= 10;
            result += x%10;
            x /= 10;
            // debug(result)
        }
        if (result > INT32_MAX) {
            return 0;
        }
        if (!sign) {
            return -result;
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.reverse(INT32_MIN) << endl;
    cout << sol.reverse(INT32_MAX) << endl;
    cout << sol.reverse(123) << endl;
    cout << sol.reverse(-123) << endl;
    cout << sol.reverse(100) << endl;
    cout << sol.reverse(-100) << endl;


    return 0;
}
