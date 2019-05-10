#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXK 405
using namespace std;

int K;
struct Block{
  int h;
  int a;
  int c;
}block[MAXK];
int dp[2][40005];

bool compare(Block p,Block q){
  return p.a<q.a;
}

int main(){
  cin>>K;
  for(int i=0;i<K;i++) cin>>block[i].h>>block[i].a>>block[i].c;
  sort(block,block+K,compare); ///盲猜先放限制高度最小的
  memset(dp,-1,sizeof dp);
  for(int i=0;i*block[0].h<=block[0].a&&i<=block[0].c;i++){
    dp[0][i*block[0].h]=i;
  }
  for(int i=1;i<K;i++){
    for(int j=0;j<=40000;j++){
      if(dp[(i-1)%2][j]>=0) dp[i%2][j]=0;
      else if(j>=block[i].h&&j<=block[i].a&&dp[i%2][j-block[i].h]<block[i].c&&dp[i%2][j-block[i].h]>=0){
        dp[i%2][j]=dp[i%2][j-block[i].h]+1;
      }
    }
  }
  int res=0;
  for(int i=0;i<=40000;i++){
    if(dp[(K-1)%2][i]>=0&&i>res) res=i;
  }
  cout<<res<<endl;
  return 0;
}
