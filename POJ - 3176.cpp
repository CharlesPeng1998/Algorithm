#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N,dp[355][355];

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<=i;j++) scanf("%d",&dp[i][j]);
  }

  for(int i=N-2;i>=0;i--){
    for(int j=0;j<=i;j++){
      dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
    }
  }

  printf("%d\n",dp[0][0]);
  return 0;
}
