// 变种01背包

#include <iostream>
#define INF 0x3f3f3f3f
#define MAXS 200005
#define ZERO 100000
#define MAXN 105
#include <string.h>
#include <algorithm>
using namespace std;

int dp[MAXS];
int n;
int s[MAXN];
int f[MAXN];
int main(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>s[i]>>f[i];
  for(int i=0;i<MAXS;i++) dp[i]=-INF;
  dp[ZERO]=0;
  for(int i=0;i<n;i++){
    if(s[i]>=0){
      for(int j=MAXS-1;j>=s[i];j--) dp[j]=max(dp[j-s[i]]+f[i],dp[j]);
    }
    else{
      for(int j=0;j<MAXS+s[i];j++) dp[j]=max(dp[j-s[i]]+f[i],dp[j]);
    }
  }
  int res=0;
  for(int i=ZERO;i<MAXS;i++){
    if(dp[i]>=0) res=max(res,i-ZERO+dp[i]);
  }
  cout<<res<<endl;
  return 0;
}
