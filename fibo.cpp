#include<bits/stdc++.h>
using namespace std;


// int fibo_r(int n){
//   cout<<"calling for "<<n<<endl;

//   if(n<=1){
//     return n;
//   }
//   return fibo_r(n-1)+fibo_r(n-2);
// }
// int main(){
//   int n;
//   cin>>n;
//   cout<<fibo_r(n)<<endl;
// }

/////Memoization.............

// int fibo_r(int n,vector<int> &memo){
//   cout<<"calling for "<<n<<endl;
//   if(n<=1){
//     return n;
//   }
//   int v1=(memo[n-1]!=-1 ? memo[n-1] : memo[n-1]=fibo_r(n-1,memo));
//   int v2=(memo[n-2]!=-1 ? memo[n-2] : memo[n-2]=fibo_r(n-2,memo));

//   return v1+v2;
// }
// int main(){
//   int n;
//   cin>>n;
//   vector<int> memo(n,-1);
//   cout<<fibo_r(n,memo)<<endl;
// }

/////Memoization.............

// int fibo_r(int n,vector<int> &memo){
//   cout<<"calling for "<<n<<endl;
//   if(n<=1){
//     return n;
//   }

//   if(memo[n]!=-1){
//     return memo[n];
//   }
  
//   return memo[n]=fibo_r(n-1,memo)+fibo_r(n-2,memo);
// }
// int main(){
//   int n;
//   cin>>n;
//   vector<int> memo(n+1,-1);
//   cout<<fibo_r(n,memo)<<endl;
// }

///////////////Tabulation//////////////////////
// int fibo_r(int n){
//   vector<int> tab(n+1,-1);
//   tab[0]=0;
//   tab[1]=1;

//   for(int i=2;i<=n;i++){
//     tab[i]=tab[i-1]+tab[i-2];
//   }
//     return tab[n];
// }
// int main(){
//   int n;
//   cin>>n;
//   cout<<fibo_r(n)<<endl;
// }


/////////////////////////////////////
int fibo_r(int n){
  int first=0;
  int second=1;

  for(int i=2;i<=n;i++){
    int temp=first+second;
    first=second;
    second=temp;
  }
  return second;
}
int main(){
  int n;
  cin>>n;
  cout<<fibo_r(n)<<endl;
}