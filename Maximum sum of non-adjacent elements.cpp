// You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

// Note:
// A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
// Input Format:
// The first line contains a single integer ‘T’ denoting the number of test cases.

// The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array.

// The second line contains ‘N’ single space-separated integers denoting the elements of the array/list.
// Output Format:
// For each test case, print a single integer that denotes the maximum sum of the non-adjacent elements.

// Print the output of each test case in a separate line.
// Note:
// You do not need to print anything; it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 500
// 1 <= N <= 1000
// 0 <= ARR[i] <= 10^5

// Where 'ARR[i]' denotes the 'i-th' element in the array/list.

// Time Limit: 1 sec.


#include<bits/stdc++.h>
using namespace std;

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n=nums.size();
//     vector<int> takeCur(n,0);
//     vector<int> nottakeCur(n,0);
//     takeCur[0]=nums[0];

//     for(int i=1;i<n;i++){
//       int tmp=max(nottakeCur[i-1],takeCur[i-1]);
//       takeCur[i]=nottakeCur[i-1]+nums[i];
//       nottakeCur[i]=tmp;
//     }
//     return max(nottakeCur[n-1],takeCur[n-1]);
// }

/////////////////////////////////////////////////////
//TLE
// int maximumNonAdjacentSum(vector<int> &nums,int idx){    
//     if(idx>=nums.size()){
//         return 0;
//     }
//     return max(maximumNonAdjacentSum(nums,idx+2)+
//                nums[idx],maximumNonAdjacentSum(nums,idx+1));
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     return maximumNonAdjacentSum(nums,0);
// }
/////////////////////////////////////////////////////

int maximumNonAdjacentSum(vector<int> &nums,int idx,vector<int> &memo){    
    if(idx>=nums.size()){
        return 0;
    }
    if(memo[idx]!=-1){
        return memo[idx];
        }
    return memo[idx]=max(maximumNonAdjacentSum(nums,idx+2,memo)+
               nums[idx],maximumNonAdjacentSum(nums,idx+1,memo));
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> memo(nums.size()+1,-1);
    return maximumNonAdjacentSum(nums,0,memo);
}
/////////////////////////////////////////////////////
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int takeCur=nums[0];
    int nottakeCur=0;
    for(int i=1;i<n;i++){
      int tmp=max(nottakeCur,takeCur);
      takeCur=nottakeCur+nums[i];
      nottakeCur=tmp;
    }
    return max(nottakeCur,takeCur);
}