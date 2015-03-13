#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int bs(const vecotr<int>& arr, int low, int high, int key){
        int mid = low + (high - low) >> 1;
        if (low > high) {
            return false;
        }
        else {
                if (arr[mid] == key) {
                    return mid;
                }
                else if (arr[mid] > key) {
                    return bs(arr, low, mid-1, key);
                }
                else {
                    return bs(arr, mid+1, high, key);
                }
        }
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        sort(numbers.begin(), numbers.end());
        for (int i=0; i<numbers.size()-1; ++i) {
            int another_num =
                bs(numbers, 0, numbers.size()-1, target-numbers[i]);
            if (another_num) {
                return vector<int>{i, another_num};
            }
        }
    }
};

int main() {
    vector<int> a{1,2,3,4,5,6,7};
    int target = 5;
    Solution sol;
    auto v = sol.twoSum(a,target);
    cout<<v[0]<<" "<<v[1]<<endl;

}
