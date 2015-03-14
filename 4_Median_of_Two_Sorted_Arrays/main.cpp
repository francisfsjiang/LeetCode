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
    int findk(int A[], int m, int B[], int n, int k){
        if (m == 0) return B[k-1];
        if (n == 0) return A[k-1];
        if (k == 1) return min(A[0], B[0]);
        int target = k>>1;
        if (min(m,n)<target){
            target = min(m,n);
        }
        if (A[target-1] < B[target-1]) return findk(A+target, m-target, B, n, k-target);
        else return findk(A, m, B+target, n-target, k-target);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)&1) {
            return findk(A,m,B,n,(m+n)/2+1);
        }
        else {
            //debug(findk(A,m,B,n,(m+n)/2))
            //debug(findk(A,m,B,n,(m+n)/2+1))
            return (double)(findk(A,m,B,n,(m+n)/2) + findk(A,m,B,n,(m+n)/2+1))/2;
        }
    }
};

int main() {
    int A[]={1,3,5,7,9};
    int m=sizeof(A)/4;
    int B[]={2,4,6,8,10};
    int n=sizeof(B)/4;
    debug(m)
    debug(n)
    Solution sol;
    cout<<sol.findMedianSortedArrays(A,m,B,n)<<endl;
    return 0;
}
