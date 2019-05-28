/*
dp[i]:
*/
#include <iostream>
#include <string.h>
#define MAXN 105
#define MAXM 100005
using namespace std;

int n,m;
int A[MAXN],C[MAXN];
int dp[MAXM];
int main(){
  while (cin>>n>>m){
    if(n==0 && m==0) break;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>C[i];
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<=m;j++){
        if(dp[j]>=0) dp[j]=0;
        else if(j>=A[i]){
          if(dp[j-A[i]]<C[i] && dp[j-A[i]]>=0) dp[j]=dp[j-A[i]]+1;
        }
      }
    }
    int res=0;
    for(int i=1;i<=m;i++){
      if(dp[i]>=0) res++;
    }
    cout<<res<<endl;
  }

  return 0;
}
