#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX_N 1005
using namespace std;
struct edge {
  int to;
  int cost;
  edge() {}
  edge(int t, int c) {
    to = t;
    cost = c;
  }
};
typedef pair<int, int> P;
vector<edge> G[MAX_N];
int N, M, X;
int d[MAX_N];
int dijkstra(int s, int X) {
  memset(d, INF, sizeof d);
  d[s] = 0;
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(make_pair(0, s));
  while (!que.empty()) {
    P p = que.top(); que.pop();
    if (d[p.second] < p.first) continue;
    for (int i = 0; i < int(G[p.second].size()); i++) {
      edge e = G[p.second][i];
      if (d[e.to] > d[p.second] + e.cost) {
        d[e.to] = d[p.second] + e.cost;
        que.push(make_pair(d[e.to], e.to));
      }
    }
  }
  return d[X];
}
int main() {
  scanf("%d%d%d", &N, &M, &X);
  for (int i = 0; i < M; i ++) {
    int A, B, T;
    scanf("%d%d%d", &A, &B, &T);
    G[A].push_back(edge(B, T));
  }
  int res = 0;
  for (int i = 1; i <= N; i ++) {
    int shortest = dijkstra(i, X) + dijkstra(X, i);
    if (shortest > res) res = shortest;
  }
  printf("%d\n", res);
  return 0;
}
