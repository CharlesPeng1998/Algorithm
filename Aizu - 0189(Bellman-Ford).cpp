#include <bits/stdc++.h>
#define MAX_V 10
#define DEBUG 0
#define MAX_E 45
#define INF 0x3f3f3f3f
using namespace std;

struct edge {
  int from;
  int to;
  int cost;
  edge(int f, int t, int c) {
    from = f;
    to = t;
    cost = c;
  }
  edge() {};
};
vector<edge> G;
int d[MAX_V];
int V;
int n;
int shortest_path(int s) {
  memset(d, INF, sizeof d);
  d[s] = 0;
  while (true) {
    bool update = false;
    for (int i = 0; i < int(G.size()); i++) {
      edge e = G[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update) break;
  }
  int res = 0;
  for (int i = 0; i <= V; i++) {
    if (d[i] != INF) res += d[i];
  }
  return res;
}
int main() {
  while (cin >> n) {
    if (n == 0) break;
    int f, t, c;
    V = 0;
    G.clear();
    for (int i = 0; i < n; i++) {
      cin >> f >> t >> c;
      G.push_back(edge(f, t, c));
      G.push_back(edge(t, f, c));
      V = max(f, V);
      V = max(t, V);
    }
    int id, ans  = INF;
    for (int i = 0; i < V; i++) {
      int shortest = shortest_path(i);
      if (shortest < ans) {
        ans = shortest;
        id = i;
      }
    }
    printf("%d %d\n", id, ans);
  }
  return 0;
}
