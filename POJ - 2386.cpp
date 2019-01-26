#include <iostream>
#include <string.h>
using namespace std;

char field[101][101];
int visited[101][101];
int N,M;
int res=0;

void dfs(int n,int m) {
  if (!(n>0 && n<=N && m>0 && m<=M)) return;

  if (field[n][m]=='W' && visited[n][m]==0) {
    visited[n][m]=1;
    dfs(n+1,m);
    dfs(n,m+1);
    dfs(n+1,m+1);
    dfs(n-1,m);
    dfs(n,m-1);
    dfs(n-1,m-1);
    dfs(n-1,m+1);
    dfs(n+1,m-1);
  }
  else return;
}

int main() {
  cin>>N>>M;
  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      cin>>field[i][j];
    }
  }
  memset(visited,0,sizeof(visited));

  for (int i=1;i<=N;i++) {
    for (int j=1;j<=M;j++) {
      if (field[i][j]=='W' && visited[i][j]==0) res++;
      dfs(i,j);
    }
  }

  cout<<res<<endl;
  return 0;
}
