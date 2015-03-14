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
    int bs(const vector<int>& arr, int low, int high, int key){
        int mid = low + ((high - low) >> 1);
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
    vector<int> twoSum(vector<int> &origin_numbers, int target) {
        vector<int> numbers(origin_numbers.begin(), origin_numbers.end());
        sort(numbers.begin(), numbers.end());
        for (int i=0; i<numbers.size()-1; ++i) {
            int another_num =
                bs(numbers, 0, i-1, target-numbers[i]);
            if (!another_num) {
                another_num = bs(numbers, i+1, numbers.size(), target-numbers[i]);
            }
            if (another_num) {
                int pos1, pos2;
                for(pos1=0;pos1<numbers.size()&&origin_numbers[pos1]!=numbers[i];++pos1);
                for(pos2=numbers.size()-1;pos2>=0&&origin_numbers[pos2]!=numbers[another_num];--pos2);
                if (pos1 > pos2) {
                    vector<int> a{pos2+1, pos1+1};
                    return a;
                }
                else {
                    vector<int> a{pos1+1, pos2+1};
                    return a;
                }
            }
        }
    }
};

int main() {
    vector<int> a{-1,-2,-3,-4,-5};
    int target = -8;
    Solution sol;
    auto v = sol.twoSum(a,target);
    cout<<v[0]<<" "<<v[1]<<endl;


}
