#include <bits/stdc++.h>
#define MAX_V 10
#define INF 0x3f3f3f3f
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
vector<edge> G[MAX_V];
int n, V;
int d[MAX_V];
int used[MAX_V];
int dijkstra(int s) {
  memset(d, INF, sizeof d);
  memset(used, 0, sizeof used);
  d[s] = 0;
  while (true) {
    int v = -1;
    for (int i = 0; i <= V; i++) {
      if (!used[i] && (v == -1 || d[i] < d[v])) v = i;
    }
    if (v == -1) break;
    used[v] = 1;
    for (int i = 0; i < int(G[v].size()); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) d[e.to] = d[v] + e.cost;
    }
  }
  int total = 0;
  for (int i = 0; i <= V; i++) total += d[i];
  return total;
}
int main() {
  while (scanf("%d", &n)) {
    if (n == 0) break;
    for (int i = 0; i < MAX_V; i++) G[i].clear();
    int a, b, c;
    V = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &a, &b, &c);
      G[a].push_back(edge(b, c));
      G[b].push_back(edge(a, c));
      V = max(V, a);
      V = max(V, b);
    }
    int id, ans = INF;
    for (int i = 0; i <= V; i++) {
      int dis = dijkstra(i);
      if (dis < ans) {
        id = i; ans = dis;
      }
    }
    printf("%d %d\n", id, ans);
  }
  return 0;
}
