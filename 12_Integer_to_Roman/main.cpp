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
    string intToRoman(int num) {
        string s;
        int count = num / 1000;
        for (size_t i = 0; i < count; i++) {
            s += "M";
            num -= 1000;
        }
        if (num >= 900) {
            s += "CM";
            num -= 900;
        }
        if (num >= 500) {
            s += "D";
            num -= 500;
        }
        if (num >= 400) {
            s += "CD";
            num -= 400;
        }
        count = num / 100;
        for (size_t i = 0; i < count; i++) {
            s += "C";
            num -= 100;
        }
        if (num >= 90) {
            s += "XC";
            num -= 90;
        }
        if (num >= 50) {
            s += "L";
            num -= 50;
        }
        if (num >= 40) {
            s += "XL";
            num -= 40;
        }
        count = num / 10;
        for (size_t i = 0; i < count; i++) {
            s += "X";
            num -= 10;
        }
        if (num >= 9) {
            s += "IX";
            num -= 9;
        }
        if (num >= 5) {
            s += "V";
            num -= 5;
        }
        if (num >= 4) {
            s += "IV";
            num -= 4;
        }
        count = num;
        for (size_t i = 0; i < count ; i++) {
            s += "I";
            num -= 1;
        }
        return s;
    }
};

int main() {
    Solution sol;
    for(int i = 1; i<=100; ++i)
        cout <<i << " " <<  sol.intToRoman(i) << endl;
    return 0;
}
