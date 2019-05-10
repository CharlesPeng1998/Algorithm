//dp求解最长上升子序列的优化O(nlogn)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#define MAXN 40005
using namespace std;

int T,N;
int a[MAXN];
int dp[MAXN]; //dp[i]：长度为i的上升子序列的最小末尾值

int main(){
  cin>>T;
  while(T--){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    memset(dp,0,sizeof dp);
    int len=1;
    dp[len]=a[0];
    for (int i=1;i<N;i++){
      if(a[i]>dp[len]) dp[++len]=a[i];
      else{
        int *p=lower_bound(dp+1,dp+len+1,a[i]);
        *p=a[i];
      }
    }
    cout<<len<<endl;
  }
  return 0;
}
