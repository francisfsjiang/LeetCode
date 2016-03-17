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

    int myAtoi(string str) {
        int head = 0;
        while(head < str.size() && str[head] == ' ') {
            ++head;
        }
        int sign = 1;
        bool already_signed = false;
        if (str[head] == '+') {
            sign = 1;
            ++head;
        }
        else if (str[head] == '-') {
            sign = -1;
            ++head;
        }
        if (!(str[head] >= '0' && str[head] <= '9')) {
            return 0;
        }
        long long res = 0;
        while (str[head] >= '0' && str[head] <= '9') {
            res *= 10;
            res += str[head] - '0';
            if ( sign == 1 && res > INT_MAX ) {
                return INT_MAX;
            }
            if ( sign == -1 && res > (double)INT_MAX+1 ) {
                return INT_MIN;
            }
            ++head;
        }
        return res*sign;
    }
};

int main() {
    Solution sol;
    assert(sol.myAtoi("123") == 123);
    assert(sol.myAtoi("+") == 0);
    assert(sol.myAtoi("-") == 0);
    assert(sol.myAtoi("-123") == -123);
    assert(sol.myAtoi("-+-123") == 0);
    assert(sol.myAtoi("+-2") == 0);
    assert(sol.myAtoi("     -123av5656") == -123);

    return 0;
}
