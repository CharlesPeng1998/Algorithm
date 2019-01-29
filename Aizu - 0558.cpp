#include <iostream>
#include <string.h>
#include <queue>
#include <utility>
#define INF 0x3f3f3f3f

using namespace std;
typedef pair<int,int> P;

//解题思路：从起始点开始，用bfs找到最近的能够吃的格子
//然后从该格子开始再次用bfs找下一个最近的能够吃的格子
//以此类推

int h,w,n;
char map[1001][1001];
int dis[1001][1001]; //记录到达某个格子所花费的时间
int res;
int si,sj;
int strength;
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

void bfs(int i,int j) {
  queue<P> que;
  que.push(P(i,j));
  for (int i=1;i<=h;i++) {
    for (int j=1;j<=w;j++) {
      dis[i][j]=INF;
    }
  }
  dis[i][j]=0;
  while (!que.empty()) {
    P p=que.front(); que.pop();
    if (int(map[p.first][p.second]-'0')==strength) {si=p.first;sj=p.second;break;} //找到可吃目标
    for (int k=0;k<4;k++) {
      int pi=p.first+di[k]; int pj=p.second+dj[k];
      if (pi>=1&&pi<=h&&pj>=1&&pj<=w&&map[pi][pj]!='X'&&dis[pi][pj]==INF) {
        que.push(P(pi,pj));
        dis[pi][pj]=dis[p.first][p.second]+1;
      }
    }
  }
  res+=dis[si][sj];
}

int main() {
  cin>>h>>w>>n;
  for (int i=1;i<=h;i++) {
    for (int j=1;j<=w;j++) {
      cin>>map[i][j];
      if (map[i][j]=='S') {si=i;sj=j;map[i][j]='.';}
    }
  }
  res=0;
  strength=1;
  for (int i=1;i<=n;i++) {
    bfs(si,sj);
    strength++;
  }
  cout<<res<<endl;
  return 0;
}
