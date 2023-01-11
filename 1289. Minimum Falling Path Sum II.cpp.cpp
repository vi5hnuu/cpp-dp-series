/*
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

Example 1:


Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
Example 2:

Input: grid = [[7]]
Output: 7
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99
*/

// class Solution {
// private:
//     int minFallingPathSum(vector<vector<int>>& grid,int row,int take) {
//         if(row>=grid.size() || take<0 || take>=grid[row].size()){
//             return INT_MAX;
//         }
//         int mn=INT_MAX;;
//         for(int i=0;i<grid[row].size();i++){
//             if(take!=i){
//                 int b=minFallingPathSum(grid,row+1,i);
//                 mn=min(mn,b);
//             }
//         }
//         return grid[row][take]+(mn==INT_MAX ? 0 : mn);
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int mn=INT_MAX;
//         int cols=grid[0].size();
        
//         for(int i=0;i<cols;i++){
//             mn=min(mn,minFallingPathSum(grid,0,i));
//         }
//         return mn;   
//     }
// };
/////////////////////////////////////////////////////////////
// class Solution {
// private:
//     int minFallingPathSum(vector<vector<int>>& grid,int row,int take,vector<vector<int>> &memo) {
//         if(row>=grid.size() || take<0 || take>=grid[row].size()){
//             return INT_MAX;
//         }
//         if(memo[row][take]!=-1){
//             return memo[row][take];
//         }
//         int mn=INT_MAX;;
//         for(int i=0;i<grid[row].size();i++){
//             if(take!=i){
//                 int b=minFallingPathSum(grid,row+1,i,memo);
//                 mn=min(mn,b);
//             }
//         }
//         return memo[row][take]=grid[row][take]+(mn==INT_MAX ? 0 : mn);
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int mn=INT_MAX;

//         int rows=grid.size();
//         int cols=grid[0].size();
//         vector<vector<int>> memo(rows,vector<int>(cols,-1));
//         for(int i=0;i<cols;i++){
//             mn=min(mn,minFallingPathSum(grid,0,i,memo));
//         }
//         return mn;   
//     }
// };
////////////////////////////////////////////////////////////////////
class Solution {
private:
    int findMin(vector<vector<int>>& grid,int row,int nottakeidx){
        int mn=INT_MAX;
        int n=grid[row].size();
        for(int i=0;i<n;i++){
            if(i!=nottakeidx)
                mn=min(mn,grid[row][i]);
        }
        return mn;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                grid[i][j]=grid[i][j]+findMin(grid,i-1,j);
            }
        }

        int mn=INT_MAX;
        for(int k=0;k<cols;k++){
            mn=min(mn,grid[rows-1][k]);
        }
        return mn;   
    }
};