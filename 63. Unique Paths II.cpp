/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/


// class Solution {
// private:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid,int i,int j) {
//         int rows=obstacleGrid.size();
//         int cols=obstacleGrid[0].size();
//         if(i== rows-1 && j==cols-1){
//             return 1;
//         }else if(i>=rows || j>=cols || obstacleGrid[i][j]==1){
//             return 0;
//         }
//         int ways=uniquePathsWithObstacles(obstacleGrid,i+1,j)+
//                 uniquePathsWithObstacles(obstacleGrid,i,j+1);
//         return ways;     
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//             return uniquePathsWithObstacles(obstacleGrid,0,0);
//     }
// };
/////////////////////////////////////////////////
// class Solution {
// private:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &memo) {
//         int rows=obstacleGrid.size();
//         int cols=obstacleGrid[0].size();
//         if(i== rows-1 && j==cols-1){
//             return 1;
//         }else if(i>=rows || j>=cols || obstacleGrid[i][j]==1){
//             return 0;
//         }
//         if(memo[i][j]!=-1){
//             return memo[i][j];
//         }
//         int ways=uniquePathsWithObstacles(obstacleGrid,i+1,j,memo)+
//                 uniquePathsWithObstacles(obstacleGrid,i,j+1,memo);
//         return memo[i][j]=ways;     
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//             int rows=obstacleGrid.size();
//             int cols=obstacleGrid[0].size();
//             vector<vector<int>> memo(rows,vector<int>(cols,-1));
//             return uniquePathsWithObstacles(obstacleGrid,0,0,memo);
//     }
// };
/////////////////////////////////////////////////
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1 || 
                (i==0 && (j-1>=0) && dp[i][j-1]==0) ||
                 (j==0 && (i-1>=0) && dp[i-1][j]==0)){
                    continue;
                 }
                
                if(i==0 || j==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
         }
         return dp[m-1][n-1];
    }

};