//Same as Maximum sub of non-adjacent elements
//for other method take ref to Maximum sum of non-adjacent.cpp
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

// class Solution {
// public:
//     int rob(vector<int>& house) {
//         vector<int> dp(100,-1);
//        return rob(0,house,dp);
//     }
//     private:
    
//     int rob(int i,vector<int>& house,vector<int> &dp) {
//         if(i>=house.size())
//             return 0;
//         if(dp[i]!=-1)
//             return dp[i];
//         int op1=house[i]+rob(i+2,house,dp);
//         int op2=0+rob(i+1,house,dp);
//         return dp[i]=max(op1,op2);
//     }
    
// };


/////////////////////////////////////////////


class Solution {
public:
    int rob(vector<int>& house) {
       int n=house.size();
        int takeCur=house[0];
        int nottakeCur=0;
        for(int i=1;i<n;i++){
        int tmp=max(nottakeCur,takeCur);
        takeCur=nottakeCur+house[i];
        nottakeCur=tmp;
        }
        return max(nottakeCur,takeCur);
    }    
};








