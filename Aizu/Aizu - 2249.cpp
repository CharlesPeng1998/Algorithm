#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#define DEBUG 0
#include <queue>
#define MAX_N 10005
#define INF 0x3f3f3f3f
using namespace std;
struct edge {
  int to;
  int dis;
  int cost;
  edge() {}
  edge(int t, int d, int c) {
    to = t;
    dis = d;
    cost = c;
  }
};
typedef pair<int, int> P;
vector<edge> G[MAX_N];
int N, M;
int d[MAX_N];
int pre[MAX_N];
int pre_cost[MAX_N];
int dijkstra(int s) {
  memset(d, INF, sizeof d);
  memset(pre, -1, sizeof pre);
  int min_cost = 0;
  d[s] = 0;
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(make_pair(0,s));
  while (!que.empty()) {
    P p = que.top(); que.pop();
    if (d[p.second] < p.first) continue;
    for (int i = 0; i < int(G[p.second].size()); i++) {
      edge e = G[p.second][i];
      if (d[e.to] > d[p.second] + e.dis) {
        if (d[e.to] == INF) min_cost += e.cost;
        else min_cost = min_cost - pre_cost[e.to] + e.cost;
        d[e.to] = d[p.second] + e.dis;
        pre[e.to] = p.second;
        pre_cost[e.to] = e.cost;
        que.push(make_pair(d[e.to], e.to));
      }
      else if (d[e.to] == d[p.second] + e.dis) {
        if (min_cost > min_cost - pre_cost[e.to] + e.cost) {
          min_cost = min_cost - pre_cost[e.to] + e.cost;
          pre[e.to] = p.second;
          pre_cost[e.to] = e.cost;
        }
      }
    }
  }
  return min_cost;
}
int main() {
  while (scanf("%d%d", &N, &M)) {
    for (int i = 0; i < MAX_N; i++) G[i].clear();
    if (N == 0 && M == 0) break;
    int u, v, d, c;
    for (int i = 0; i < M; i++) {
      scanf("%d%d%d%d", &u, &v, &d, &c);
      G[u].push_back(edge(v, d, c));
      G[v].push_back(edge(u, d, c));
    }
    printf("%d\n", dijkstra(1));
  }
  return 0;
}
