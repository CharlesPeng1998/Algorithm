#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
#define MAXN 2005
using namespace std;

int N;
int A[MAXN];
int B[MAXN];
int dp[2][MAXN];

int main(){
  cin>>N;
  for(int i=0;i<N;i++) {
    cin>>A[i];
    B[i]=A[i];
  }
  sort(B,B+N);
  for(int i=0;i<N;i++) dp[0][i]=abs(A[0]-B[i]);
  for(int i=1;i<N;i++){
    int min_temp=dp[(i-1)%2][0];
    for(int j=0;j<N;j++){
      min_temp=min(min_temp,dp[(i-1)%2][j]);
      dp[i%2][j]=min_temp+abs(A[i]-B[j]);
    }
  }
  int res=INF;
  for(int i=0;i<N;i++){
    if(dp[(N-1)%2][i]<res) res=dp[(N-1)%2][i];
  }
  cout<<res<<endl;
  return 0;
}
