/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/


//TLE 38/49
// class Solution {
//     int minFallingPathSum(vector<vector<int>>& matrix,int row,int takeInd) {
//         if(row>=matrix.size() || takeInd<0 || takeInd>=matrix[row].size()){
//             return INT_MAX;
//         }

//         int a=minFallingPathSum(matrix,row+1,takeInd-1);
//         int b=minFallingPathSum(matrix,row+1,takeInd);
//         int c=minFallingPathSum(matrix,row+1,takeInd+1);
//         return matrix[row][takeInd]+(min(min(a,b),c)==INT_MAX ? 0 : min(min(a,b),c) );
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int cols=matrix[0].size();
//         int mn=INT_MAX;
//         for(int i=0;i<cols;i++){
//             mn=min(mn,minFallingPathSum(matrix,0,i));
//         }
//         return mn;    
//     }
// };

/////////////////////////////////////////////////
//done
// class Solution {
//     int minFallingPathSum(vector<vector<int>>& matrix,int row,int takeInd,vector<vector<int>> &memo) {
//         if(row>=matrix.size() || takeInd<0 || takeInd>=matrix[row].size()){
//             return INT_MAX;
//         }
//         if(memo[row][takeInd]!=-1){
//             return memo[row][takeInd];
//         }
//         int a=minFallingPathSum(matrix,row+1,takeInd-1,memo);
//         int b=minFallingPathSum(matrix,row+1,takeInd,memo);
//         int c=minFallingPathSum(matrix,row+1,takeInd+1,memo);
//         return memo[row][takeInd]=matrix[row][takeInd]+(min(min(a,b),c)==INT_MAX ? 0 : min(min(a,b),c) );
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows=matrix.size();
//         int cols=matrix[0].size();
//         vector<vector<int>> memo(rows,vector<int>(cols,-1));
//         int mn=INT_MAX;
//         for(int i=0;i<cols;i++){
//             mn=min(mn,minFallingPathSum(matrix,0,i,memo));
//         }
//         return mn;    
//     }
// };

/////////////////////////////
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        for(int i=rows-2;i>=0;i--){
            for(int j=0;j<cols;j++){
                int mn=INT_MAX;
                if(j-1>=0){
                    int a=matrix[i+1][j-1];
                    mn=min(mn,a);
                }
                int b=matrix[i+1][j];
                if(j+1<cols){
                    int b=matrix[i+1][j+1];
                    mn=min(mn,b);
                }
                matrix[i][j]=matrix[i][j]+min(mn,b);
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<cols;i++){
            ans=min(ans,matrix[0][i]);
        }
        return ans;               
    }
};