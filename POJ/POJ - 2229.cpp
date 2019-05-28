#include <iostream>
#include <cmath>
#define MAXN 1000001
using namespace std;

int N;
int pow2[20];
int dp[MAXN];

int main(){
  cin>>N;
  pow2[0]=1;
  for(int i=1;i<20;i++) pow2[i]=pow2[i-1]*2;
  dp[0]=1;
  for(int i=0;i<20;i++){
    for(int j=pow2[i];j<=N;j++){
      dp[j]=(dp[j]+dp[j-pow2[i]])%1000000000;
    }
  }
  cout<<dp[N]<<endl;
  return 0;
}
