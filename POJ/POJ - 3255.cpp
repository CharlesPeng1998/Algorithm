#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define MAX_N 50005

using namespace std;

typedef pair<int, int> P;
struct edge {
  int to, cost;
  edge() {}
  edge(int t, int c): to(t), cost(c) {}
};
vector<edge> G[MAX_N];
int N, R;
int dis[MAX_N];
int dis2[MAX_N];
int dijkstra() {
  memset(dis, INF, sizeof dis);
  memset(dis2, INF, sizeof dis2);
  priority_queue<P, vector<P>, greater<P> > que;
  dis[1] = 0;
  que.push(make_pair(0,1));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second, d = p.first;
    if (d > dis2[v]) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      int d2 = d + e.cost;
      if (dis[e.to] > d2) {
        swap(dis[e.to], d2);
        que.push(make_pair(dis[e.to], e.to));
      }
      if (d2 < dis2[e.to] && d2 > dis[e.to]) {
        dis2[e.to] = d2;
        que.push(make_pair(dis2[e.to], e.to));
      }
    }
  }
  return dis2[N];
}
int main() {
  scanf("%d%d", &N, &R);
  for (int i = 0; i < R; i++) {
    int A, B, D;
    scanf("%d%d%d", &A, &B, &D);
    G[A].push_back(edge(B,D));
    G[B].push_back(edge(A,D));
  }
  printf("%d\n", dijkstra());
  return 0;
}
