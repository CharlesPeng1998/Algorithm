#include <iostream>
#include <string.h>
using namespace std;

char floor[21][21];
int visited[21][21];
int H,W;
int res;
int dx[4]{1,0,-1,0};
int dy[4]={0,1,0,-1};


void dfs(int y,int x) {
  if (!(y>0 && y<=H && x>0 && x<=W)) return;

  if ((floor[y][x]=='.' || floor[y][x]=='@') && visited[y][x]==0) {
    res++;
    visited[y][x]=1;
    for (int i=0;i<4;i++) {
      int nx=x+dx[i];
      int ny=y+dy[i];
      dfs(ny,nx);
    }
  }
}

int main() {
  while (cin>>W>>H) {
    res=0;
    if (W==0 && H==0) break;

    for (int i=1;i<=H;i++) {
      for (int j=1;j<=W;j++) {
        cin>>floor[i][j];
      }
    }

    memset(visited,0,sizeof(visited));
    for (int i=1;i<=H;i++) {
      for (int j=1;j<=W;j++) {
        if (floor[i][j]=='@') dfs(i,j);
      }
    }

    cout<<res<<endl;
  }
  return 0;
}
