#include <iostream>
#include <queue>
#include <utility>
#define INF 0x3f3f3f3f

using namespace std;
typedef pair<int,int> P;

int w,h,n;
int res;
int si,sj;
int strength;
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
char map[1001][1001];
int dis[1001][1001];

void bfs(int i,int j) {
  queue<P> que;
  for (int i=1;i<=h;i++) {
    for (int j=1;j<=w;j++) {
      dis[i][j]=INF;
    }
  }
  que.push(P(i,j));
  dis[i][j]=0;
  while (!que.empty()) {
    P p=que.front(); que.pop();
    if (int(map[p.first][p.second]-'0')==strength) {si=p.first;sj=p.second;break;}
    for (int k=0;k<4;k++) {
      int pi=p.first+di[k]; int pj=p.second+dj[k];
      if (pi>0&&pi<=h&&pj>0&&pj<=w&&map[pi][pj]!='X'&&dis[pi][pj]==INF) {
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
      if (map[i][j]=='S') {si=i;sj=j;}
    }
  }
  strength=1; res=0;
  for (int i=1;i<=n;i++) {
    bfs(si,sj);
    strength++;
  }
  cout<<res<<endl;
  return 0;
}
