#include<iostream>
#include <string>
#include <map>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int N,M;
pair<int,int> cost[255];
int dp[2019][2019];
string s;
int main(){
  cin>>N>>M;
  cin>>s;
  char character;
  int add,del;
  for(int i=0;i<N;i++){
    cin>>character>>add>>del;
    cost[character].first=add;
    cost[character].second=del;
  }
  memset(dp,0,sizeof(dp));
  //遍历方式为按照字符串长度从小到大进行
  for(int i=1;i<M;i++){
    for(int j=0;j+i<M;j++){
      dp[j][j+i]=INF; //因为要求最小值，因此先初始为INF
      if(s[j]==s[i+j]) dp[j][j+i]=dp[j+1][j+i-1];
      else{
        int a=dp[j+1][j+i]+min(cost[s[j]].first,cost[s[j]].second);
        int b=dp[j][j+i-1]+min(cost[s[j+i]].first,cost[s[j+i]].second);
        dp[j][j+i]=min(a,b);
      }
    }
  }
  cout<<dp[0][M-1]<<endl;
  return 0;
}
