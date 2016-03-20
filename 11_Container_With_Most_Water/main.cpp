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
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int max = 0;
        while(left < right)
        {
            int area = (right - left) * (height[left] < height[right] ? height[left++] : height[right--]);
            max = max > area? max : area;
        }
        return max;
    }
};

int main() {

    return 0;
}
