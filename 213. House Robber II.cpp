/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        //we run house robber code for 1 to n-1 and for  0 to n-2
        int n=nums.size();
        if(n<=1){
            //1 <= nums.length <= 100
            return nums[0];
        }
        int taken0=nums[0],taken1=nums[1];
        int nottaken0=0,nottaken1=0;

        //not including last el and including first one
        for(int i=1;i<n-1;i++){
            int tmp=max(taken0,nottaken0);
            taken0=nottaken0+nums[i];
            nottaken0=tmp;
        }

        //including last el and not including first one
        for(int j=2;j<n;j++){
            int tmp=max(taken1,nottaken1);
            taken1=nottaken1+nums[j];
            nottaken1=tmp;
        }

        return max(max(taken0,nottaken0),max(taken1,nottaken1));
    }
};