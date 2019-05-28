#include <iostream>
#include <string.h>
using namespace std;

char field[101][101];
int visited[101][101];
int H,W;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int res;

void dfs(int i,int j,char target) {
  if (!(i>0 && i<=H && j>0 && j<=W)) return;
  if (field[i][j]==target && visited[i][j]==0) {
    visited[i][j]=1;
    for (int k=0;k<4;k++) {
      int ni=i+dy[k]; int nj=j+dx[k];
      dfs(ni,nj,target);
    }
  }
}

int main() {
  while (cin>>H>>W) {
    res=0;
    if (H==0 && W==0) break;
    for (int i=1;i<=H;i++) {
      for (int j=1;j<=W;j++) {
        cin>>field[i][j];
      }
    }
    memset(visited,0,sizeof(visited));
    for (int i=1;i<=H;i++) {
      for (int j=1;j<=W;j++) {
        if (visited[i][j]==0) {
          res++;
          dfs(i,j,field[i][j]);
        }
      }
    }
    cout<<res<<endl;
  }
  return 0;
}
