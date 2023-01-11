/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer,' N’, denoting the number of days.

The next ‘N’ lines of each test case have 3 integers corresponding to POINTS[i].
Output Format:
For each test case, return an integer corresponding to the maximum coins  Ninja can collect.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= values of POINTS arrays <= 100 .

Time limit: 1 sec
*/


//Recursion

#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int idx, vector<vector<int>> &points,int last){
    if(idx<0){
      return 0;
    }
    int mx=0;
    int nt=ninjaTraining(idx-1,points,-1);
    for(int i=0;i<points[idx].size();i++){
      int tk=0;
      if(last!=i)
        tk=ninjaTraining(idx-1,points,i)+points[idx][i];
      mx=max(mx,tk);
    }
    return max(mx,nt);
}
int ninjaTraining(int n, vector<vector<int>> &points){
    return ninjaTraining(n-1,points,-1);
}

////////////////////////////////////////////////////////////////////
//Recursion + memo
int ninjaTraining(int idx, vector<vector<int>> &points,int last,vector<vector<int>> &dp){
    if(idx<0){
      return 0;
    }
    
    if(dp[idx][last]!=-1){
      return dp[idx][last];
    }
    int mx=0;
    for(int i=0;i<points[idx].size();i++){
      int tk=0;
      if(last!=i)
        tk=ninjaTraining(idx-1,points,i,dp)+points[idx][i];
      mx=max(mx,tk);
    }
    return dp[idx][last]=mx;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(points.size(),vector<int>(4,-1));
    return ninjaTraining(n-1,points,3,dp);
}

////////////////////////////////////////////////////////////////////
//Tabulation
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(3,-1));
    dp[0][0]=points[0][0];
    dp[0][1]=points[0][1];
    dp[0][2]=points[0][2];

    for(int i=1;i<n;i++){
        int take0=max(dp[i-1][1],dp[i-1][2])+points[i][0];
        int take1=max(dp[i-1][0],dp[i-1][2])+points[i][1];
        int take2=max(dp[i-1][0],dp[i-1][1])+points[i][2];
        dp[i][0]=take0;
        dp[i][1]=take1;
        dp[i][2]=take2;
    }

    return max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}
////////////////////////////////////////////////////////////////
//Tabulation reduced
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<int> dp(3,-1);
    dp[0]=points[0][0];
    dp[1]=points[0][1];
    dp[2]=points[0][2];

    for(int i=1;i<n;i++){
        int take0=max(dp[1],dp[2])+points[i][0];
        int take1=max(dp[0],dp[2])+points[i][1];
        int take2=max(dp[0],dp[1])+points[i][2];
        dp[0]=take0;
        dp[1]=take1;
        dp[2]=take2;
    }

    return max(max(dp[0],dp[1]),dp[2]);
}