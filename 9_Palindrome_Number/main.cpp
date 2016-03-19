#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

#define debug(x) cout<<#x<<" = "<<x<<endl;
#define debugs(arr,num) cout<<#arr<<" = ";for(int zz=0;zz<num;zz++)cout<<arr[zz]<<" ";cout<<endl;

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int reversed_half = 0, left_half = x, total = x;
        while (total) {
            reversed_half = reversed_half * 10 + left_half % 10;
            left_half /= 10;
            total /= 100;
        }
        return reversed_half == left_half || reversed_half / 10 == left_half;
    }
};

int main() {
    return 0;
}
