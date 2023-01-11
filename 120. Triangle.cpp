/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/


//TLE 42/44
// class Solution {
// private:
//     int minimumTotal(vector<vector<int>>& triangle,int row,int take) {
//         if(row>=triangle.size() || take<0 || take>=triangle[row].size()){
//             return 0;
//         }

//         int mn=triangle[row][take]+
//                 min(minimumTotal(triangle,row+1,take),minimumTotal(triangle,row+1,take+1));
//         return mn;
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return minimumTotal(triangle,0,0);
//     }
// };

///////////////////////////////////////////////////////////

// class Solution {
// private:
//     int minimumTotal(vector<vector<int>>& triangle,int row,int take,vector<vector<int>> &memo) {
//         if(row>=triangle.size() || take<0 || take>=triangle[row].size()){
//             return 0;
//         }
//         if(memo[row][take]!=-1){
//             return memo[row][take];
//         }
//         int mn=triangle[row][take]+
//                 min(minimumTotal(triangle,row+1,take,memo),minimumTotal(triangle,row+1,take+1,memo));
//         return memo[row][take]=mn;
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int rows=triangle.size();
//         int cols=triangle[rows-1].size();
//         vector<vector<int>> memo(rows,vector<int>(cols,-1));
//         return minimumTotal(triangle,0,0,memo);
//     }
// };

///////////////////////////////////////////////////////////

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        for(int i=1;i<rows;i++){
            int cols=triangle[i].size();
            for(int j=0;j<cols;j++){
                int a=INT_MAX;
                int b=INT_MAX;
                if(i-1>=0 && j<triangle[i-1].size()){
                    a=triangle[i-1][j];
                   
                }
                 if(i-1>=0 && j-1>=0)
                        b=triangle[i-1][j-1];
                triangle[i][j]=triangle[i][j]+min(a,b);
            }
        }

        
        int mn=INT_MAX;
        for(int i=0;i<triangle[rows-1].size();i++){
            mn=min(mn,triangle[rows-1][i]);
        }
        return mn;
    }
};