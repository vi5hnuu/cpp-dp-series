#include<bits/stdc++.h>
using namespace std;

//TLE
// int countDistinctWays(int nStairs) {
//   if(nStairs==0){
//     return 1;
//   }else if(nStairs<0){
//     return 0;
//   }

//   return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
// }

/////////////////////////////////
// long long countDistinctWays(int nStairs) {
//   vector<long long> tab(nStairs+1,0);
//   tab[1]=tab[0]=1;


//   for(int i=2;i<=nStairs;i++){
//     tab[i]=tab[i-1]+tab[i-2];
//   }
//   return tab[nStairs];
// }

/////////////////////////////////
long long countDistinctWays(int nStairs) {
  long long fstep_way=1;
  long long sstep_way=1;

  for(int i=2;i<=nStairs;i++){
    long long curStep_ways=fstep_way+sstep_way;
    fstep_way=sstep_way;
    sstep_way=curStep_ways;
  }
  return sstep_way;
}