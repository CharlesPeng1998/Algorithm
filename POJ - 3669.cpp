//本题数据有毒：存在一个数据坐标超过300
//本题数据输入量较大，使用iostream会TLE，改用标准输入

#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
#define judge(x,y) (x>=0&&x<=301&&y>=0&&y<=301)


using namespace std;
typedef pair<int,int> P;
int map[302][302];
int d[302][302];
int ruin_time[302][302]; //这个数组的大小和上面两个不同步为什么会Runtime Error
int m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int res;

void bfs(int x,int y) {
  if (map[y][x]==1&&ruin_time[y][x]==0) {
    res=-1; return;
  }
  queue<P> que;
  que.push(P(x,y));
  for (int i=0;i<=301;i++) {
    for (int j=0;j<=301;j++) {
      d[i][j]=INF;
    }
  }
  d[y][x]=0;
  while (!que.empty()) {
    P p=que.front(); que.pop();
    if (map[p.second][p.first]==0) {res+=d[p.second][p.first];return;}
    for (int i=0;i<4;i++) {
      int px=p.first+dx[i]; int py=p.second+dy[i];
      if (judge(px,py)&&map[py][px]==0&&d[py][px]==INF) {
        que.push(P(px,py));
        d[py][px]=d[p.second][p.first]+1;
      }
      else if(judge(px,py)&&map[py][px]==1&&d[p.second][p.first]+1<ruin_time[py][px]&&d[py][px]==INF) {
        que.push(P(px,py));
        d[py][px]=d[p.second][p.first]+1;
      }
    }
  }
  res=-1;
  return;
}


int main() {
  int x,y,t;
  memset(map,0,sizeof(map));
  res=0;
  //cin>>m;
  scanf("%d",&m);
  for (int i=0;i<m;i++) {
    //cin>>x>>y>>t;
    scanf("%d %d %d",&x,&y,&t);
    map[y][x]=1; ruin_time[y][x]=(ruin_time[y][x]<t&&ruin_time[y][x]!=0)?ruin_time[y][x]:t;
    for (int k=0;k<4;k++) {
      if (judge(x+dx[k],y+dy[k])) {
        map[y+dy[k]][x+dx[k]]=1;
        ruin_time[y+dy[k]][x+dx[k]]=(ruin_time[y+dy[k]][x+dx[k]]<t&&ruin_time[y+dy[k]][x+dx[k]]!=0)?ruin_time[y+dy[k]][x+dx[k]]:t;
      }
    }
  }
  bfs(0,0);
  cout<<res<<endl;
  return 0;
}
