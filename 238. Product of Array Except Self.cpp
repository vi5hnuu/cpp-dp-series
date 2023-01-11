/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> prefix(n,0);
//         vector<int> suffix(n,0);
//         suffix[n-1]=nums[n-1];
//         prefix[0]=nums[0];
//         for(int i=1;i<n;i++){
//                 prefix[i]=prefix[i-1]*nums[i];
//         }


//         for(int j=n-2;j>=0;j--){
//                 suffix[j]=suffix[j+1]*nums[j];
//         }

//         vector<int> ans(n,0);
//         for(int i=0;i<n;i++){
//             ans[i]=(i+1<n ? suffix[i+1] : 1)*(i-1>=0 ? prefix[i-1] : 1);
//         }
//         return ans;
//     }
// };

/////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int suffix=1;
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCount++;
            }else{
                suffix*=nums[i];
            }
        }

        int prefix=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCount--;
            }else{
                suffix/=nums[i];
            }
            if(zeroCount>0){
                ans[i]=0;
            }else{
                ans[i]=suffix*prefix;
            }
            prefix*=nums[i];
            
        }
        return ans;
    }
};