/*
dp[j]：用前i种硬币组成j元后第i种硬币剩余数量
用一维数组递推，节省空间
*/

#include <iostream>
#include <string.h>
#define MAXM 100005
#define MAXN 105
#define val first
#define num second
using namespace std;

int n,m;
int dp[MAXM];
pair<int,int> coin[MAXN];

int main(){
  while(cin>>n>>m){
    if(n==0&&m==0) break;
    for(int i=0;i<n;i++) cin>>coin[i].val;
    for(int i=0;i<n;i++) cin>>coin[i].num;
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<=m;j++){
        if(dp[j]>=0) dp[j]=coin[i].num;
        else if(j<coin[i].val||dp[j-coin[i].val]<=0) dp[j]=-1;
        else if(dp[j-coin[i].val]) dp[j]=dp[j-coin[i].val]-1;
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
