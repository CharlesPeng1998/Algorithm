#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 1000005
#define MAXM 1005
using namespace std;

int N,M,R;
struct Interval{
  int begin;
  int end;
  int length;
  int efficiency;
}interval[MAXM];
int dp[MAXM];

bool compare(Interval a,Interval b){
  return a.begin<b.begin;
}

int main(){
  cin>>N>>M>>R;
  for(int i=1;i<=M;i++){
    cin>>interval[i].begin>>interval[i].end>>interval[i].efficiency;
  }
  memset(dp,0,sizeof(dp));
  sort(interval+1,interval+1+M,compare);
  for(int i=1;i<=M;i++){
    for(int j=0;j<M;j++){
      if(j==0){
        dp[i]=interval[i].efficiency;
      }
      else{
        if(interval[j].end+R<=interval[i].begin){
          dp[i]=max(dp[i],dp[j]+interval[i].efficiency);
        }
      }
    }
  }
  int res=0;
  for(int i=1;i<=M;i++){
    if(dp[i]>res) res=dp[i];
  }
  cout<<res<<endl;
  return 0;
}
