#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 100
#define MAXM 100000
#define val first
#define num second
using namespace std;

int n,m;
char dp[MAXN][MAXM];
pair<int,int> coin[MAXN];

bool compare(pair<int,int>a,pair<int,int>b){
  return a.val<b.val;
}

int main(){
  while(cin>>n>>m){
    if(n==0&&m==0) break;
    int res=0;
    for(int i=0;i<n;i++) cin>>coin[i].val;
    for(int i=0;i<n;i++) cin>>coin[i].num;
    sort(coin,coin+n,compare);
    memset(dp,0,sizeof dp);
    for(int i=0;i<n;i++){
      for(int j=0;j<=m;j++){
        if(j==0){
          dp[i][j]=1;continue;
        }
        if(i==0){
           if(j%coin[i].val==0&&j/coin[i].val<=coin[i].num) dp[i][j]=1;
        }
        else{
          for(int k=0;k<=coin[i].num&&j-k*coin[i].val>=0;k++){
            if(dp[i-1][j-k*coin[i].val]) dp[i][j]=1;
          }
        }
        if(i==n-1&&dp[i][j]) res++;
      }
    }
    cout<<res<<endl;
  }
  return 0;
}
