// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

//n= 1, 2, 3, 4, 5, 6, 7, 8, 9 ...

#include<bits/stdc++.h>
using namespace std;

// int frogJump(int n, vector<int> &heights){
//     if(n<=1){
//       return 0;
//     } else if(n<=2){
//       return abs(heights[n-1]-heights[0]);
//     }
//   return min(frogJump(n-1,heights)+(abs(heights[n-1]-heights[n-2])),
//   frogJump(n-2,heights)+(abs(heights[n-1]-heights[n-3])));     
// }

///////////////////////////////////////////////

#include <bits/stdc++.h> 


int frogJump(int n, vector<int> &heights,vector<int> &memo){
   if(n<=1){
      return 0;
    } else if(n<=2){
      return abs(heights[n-1]-heights[0]);
    }

    if(memo[n]!=-1){
        return memo[n];
    }

  return memo[n]=min(frogJump(n-1,heights,memo)+(abs(heights[n-1]-heights[n-2])),
  frogJump(n-2,heights,memo)+(abs(heights[n-1]-heights[n-3])));     
}

int frogJump(int n, vector<int> &heights){
    vector<int> memo(n+1,-1);
    return frogJump(n,heights,memo);
}

/////////////////////////////////////////
// #include <bits/stdc++.h> 


// int frogJump(int n, vector<int> &heights){
//     //step start from 1 [n]
//     vector<int> dp(n+1,0);
//     if(n>2){
//         dp[2]=abs(heights[1]-heights[0]);
//     }
//     for(int i=3;i<=n;i++){
//       int f=dp[i-1]+abs(heights[i-1]-heights[i-2]);
//       int s=dp[i-2]+abs(heights[i-1]-heights[i-3]);
//       dp[i]=min(f,s);
//     }
//      return dp[n];
// }

///////////////////////////////////////////////

// #include <bits/stdc++.h> 


// int frogJump(int n, vector<int> &heights){
//     //step start from 1 [n]
//     if(n<=1){
//       return 0;
//     }

//     int f=0; //n==1
//     int s=abs(heights[1]-heights[0]);//n==2
//     for(int i=3;i<=n;i++){
//       int f1=s+abs(heights[i-1]-heights[i-2]);
//       int s1=f+abs(heights[i-1]-heights[i-3]);
//       int mn=min(f1,s1);
//       f=s;
//       s=mn;
//     }
//      return s;
// }

///////////////////////
//k jump

// #include <bits/stdc++.h> 


// int frogJump(int n,int k, vector<int> &heights,vector<int> &memo){
//    if(n<=1){
//       return 0;
//     }

//     if(memo[n]!=-1){
//         return memo[n];
//     }

//     int mn=INT_MAX;
//   for(int i=1;i<=k && (n-i>=1);i++){
//       int tmp=frogJump(n-i,k,heights,memo)+(abs(heights[n-1]-heights[n-1-i]));
//       mn=min(mn,tmp);
//   }
//   return memo[n]=mn;     
// }

// int frogJump(int n, vector<int> &heights){
//     vector<int> memo(n+1,-1);
//     return frogJump(n,2,heights,memo);
// }

/////////////////////////////////////////
#include <bits/stdc++.h> 


int frogJump(int n,int k, vector<int> &heights){
    //step start from 1 [n]
    vector<int> dp(n+1,0);
    if(n>2){
        dp[2]=abs(heights[1]-heights[0]);
    }
    for(int i=3;i<=n;i++){
      int mn=INT_MAX;
        for(int j=1;j<=k && (i-j>=1);j++){
          int tmp=dp[i-j]+(abs(heights[n-1]-heights[n-1-j]));
          mn=min(mn,tmp);
        }
      dp[i]=mn;
    }
     return dp[n];
}
