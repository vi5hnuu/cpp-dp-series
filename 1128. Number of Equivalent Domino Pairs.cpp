/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
Example 2:

Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3
 

Constraints:

1 <= dominoes.length <= 4 * 104
dominoes[i].length == 2
1 <= dominoes[i][j] <= 9
*/


// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         map<int,int> mp;
//         for(const vector<int> &domino:dominoes){
//             int mpng=min(domino[0],domino[1])*10+max(domino[0],domino[1]);
//             mp[mpng]++;
//         }
//         map<int,int>::iterator itr=mp.begin();
//         int ans=0;
//         while(itr!=mp.end()){
//             ans+=(itr->second*(itr->second-1)/2);
//             itr++;
//         }
//         return ans;
//     }
// };
///////////////////////////////////////////////////////////////////
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int,int> mp;
        int ans=0;
        for(const vector<int> &domino:dominoes){
            int mpng=min(domino[0],domino[1])*10+max(domino[0],domino[1]);
            ans+=mp[mpng]++;//pair sum [inc after]
        }
        return ans;
    }
};