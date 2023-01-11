/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //This is wrong... [2,1,3,null,4]
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         if(!root){
//             return 0;
//         }

//         queue<TreeNode*> nodes;
//         nodes.push(root);
//         vector<int> vals;
//         while(!nodes.empty()){
//             int sz=nodes.size();
//             int levelSum=0;
//             while(sz>0){
//                 sz--;
//                 TreeNode *node=nodes.front();
//                 nodes.pop();
//                 levelSum+=node->val;
                
//                 if(node->left){
//                     nodes.push(node->left);
//                 }
                
//                 if(node->right){
//                     nodes.push(node->right);
//                 }
//             }
//             vals.push_back(levelSum);
//         }

//         int taken=vals[0];
//         int notTaken=0;
//         for(int i=1;i<vals.size();i++){
//             int tmp=max(taken,notTaken);
//             taken=notTaken+vals[i];
//             notTaken=tmp;
//         }

//         return max(taken,notTaken);
//     }
// };

//////////////////////////////////////////////////

/*
TLE for

[79,99,77,null,null,null,69,null,60,53,null,73,11,null,null,null,62,27,62,null,null,98,50,null,null,90,48,82,null,null,null,55,64,null,null,73,56,6,47,null,93,null,null,75,44,30,82,null,null,null,null,null,null,57,36,89,42,null,null,76,10,null,null,null,null,null,32,4,18,null,null,1,7,null,null,42,64,null,null,39,76,null,null,6,null,66,8,96,91,38,38,null,null,null,null,74,42,null,null,null,10,40,5,null,null,null,null,28,8,24,47,null,null,null,17,36,50,19,63,33,89,null,null,null,null,null,null,null,null,94,72,null,null,79,25,null,null,51,null,70,84,43,null,64,35,null,null,null,null,40,78,null,null,35,42,98,96,null,null,82,26,null,null,null,null,48,91,null,null,35,93,86,42,null,null,null,null,0,61,null,null,67,null,53,48,null,null,82,30,null,97,null,null,null,1,null,null]
*/
// class Solution {
//     int rob(TreeNode* root,bool robMe) {
//         if(!root){
//             return 0;
//         }

//         if(robMe){
//             return root->val+rob(root->left,!robMe)+rob(root->right,!robMe);
//         }else{
//             int a=rob(root->left,!robMe);
//             int b=rob(root->right,!robMe);
//             int c=rob(root->left,robMe);
//             int d=rob(root->right,robMe);
//             return max(max(a+b,c+d),max(a+d,b+c));
//         }
//     }
// public:
//     int rob(TreeNode* root) {
//         return max(rob(root,true),rob(root,false));
//     }
// };

///////////////////////////
// class Solution {
// public:
//     int rob(TreeNode *root) {
//         if (!root) return 0;
        
//         int val = 0;
        
//         if (root->left) {
//             val += rob(root->left->left) + rob(root->left->right);
//         }
        
//         if (root->right) {
//             val += rob(root->right->left) + rob(root->right->right);
//         }
        
//         return max(val + root->val, rob(root->left) + rob(root->right));
//     }
// };

///////////////////////////////////////////////////////////////////////////////
//Tle...
// class Solution {
// private:
//     int rob(TreeNode *root,map<TreeNode*,int> &dp) {
//         if (!root) return 0;
        
//         const auto itr=dp.find(root);
//         if(itr!=dp.end()){
//             return itr->second; 
//         }

//         int val = 0;
//         if (root->left) {
//             val += rob(root->left->left) + rob(root->left->right);
//         }
        
//         if (root->right) {
//             val += rob(root->right->left) + rob(root->right->right);
//         }
        
//         return dp[root]=max(val + root->val, rob(root->left) + rob(root->right));
//     }
// public:
//     int rob(TreeNode *root) {
//         map<TreeNode*,int> dp;
//         return rob(root,dp);
//     }
// };

//////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    vector<int> robSub(TreeNode *root) {
         if (!root) 
            return {0,0};
    
        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);
        vector<int> res(2,0);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);//not take
        res[1] = root->val + left[0] + right[0]; //take
        
        return res;
    }
public:
    int rob(TreeNode *root) {
        vector<int> res=robSub(root);
        return max(res[0],res[1]);
    }
};











