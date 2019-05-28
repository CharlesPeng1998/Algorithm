#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int T,A,S,B;
int family[1005];
int dp[1005][100005];
int main(){
  scanf("%d%d%d%d",&T,&A,&S,&B);
  int type;
  for(int i=0;i<A;i++){
    scanf("%d",&type);
    family[type]++;
  }
  for(int i=1;i<=T;i++) dp[i][0]=1; //初始状态
  for(int i=0;i<=family[1];i++) dp[1][i]=1;
  for(int i=2;i<=T;i++){
    for(int j=1;j<=B;j++){
      for(int k=0;k<=family[i];k++){
        if(j>=k) dp[i][j]=(dp[i][j]+dp[i-1][j-k])%1000000; //注意这里也要取模
        else break;
      }
    }
  }
  int res=0;
  for(int i=S;i<=B;i++){
    res=(res+dp[T][i])%1000000;
  }
  cout<<res<<endl;
  return 0;
}
