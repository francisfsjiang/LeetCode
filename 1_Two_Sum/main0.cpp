#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>

#define debug(x)  cout<<#x<<" = "<<x<<endl;
#define debugs(arr,num) cout<<#arr<<" = ";for(int zz=0;zz<num;zz++)cout<<arr[zz]<<" ";cout<<endl;

using namespace std;

class Solution {
public:
    vector<int> make_vector(int a,int b) {
        vector<int> c{min(a+1,b+1), max(a+1,b+1)};
        return c;
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_multimap<int, int> umap;
        for (int i=0;i<numbers.size();++i){
            umap.insert(make_pair(numbers[i], i));
        }
        for (int i=0;i<numbers.size();++i){
            if (numbers[i]*2 == target) {
                auto p = umap.equal_range(numbers[i]);
                auto first=p.first++;
                auto second=p.first;
                if (p.first != umap.end() && second != p.second) {
                    return make_vector(first->second, second->second);
                }
            }
            else {
                auto p = umap.find(target-numbers[i]);
                if (p!=umap.end()) {
                    return make_vector(i, p->second);
                }
            }
        }
        return make_vector(1,2);
    }
};

int main() {
    vector<int> a{3,2,4};
    int target = 6;
    Solution sol;
    auto v = sol.twoSum(a,target);
    cout<<v[0]<<" "<<v[1]<<endl;
}
