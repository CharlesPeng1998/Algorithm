#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXT 1005
#define MAXW 35
using namespace std;

int T,W;
int dp[MAXT][MAXW];
int tree_pm[MAXT];
int main(){
  cin>>T>>W;
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=T;i++) cin>>tree_pm[i];

  //考虑t=1时的初始情况
  if(tree_pm[1]==1){
    /*若第一个从树1掉落，则不走便可得到一个；
    走了则没有
    */
    dp[1][0]=1;
    dp[1][1]=0;
  }
  else if(tree_pm[1]==2){
    /*若第一个从树2掉落，则走便可得到一个；
    不走便没有。
    */
    dp[1][0]=0;
    dp[1][1]=1;
  }

  for(int i=2;i<=T;i++){
    for(int j=0;j<=W;j++){
      if(j==0) {
        dp[i][j]=dp[i-1][j]+tree_pm[i]%2;
        continue;
      }
      dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
      if(j%2+1==tree_pm[i]) dp[i][j]++;
    }
  }

  int max=dp[T][0];
  for(int i=1;i<=W;i++){
    if(dp[T][i]>max) max=dp[T][i];
  }

  cout<<max<<endl;
  return 0;
}
