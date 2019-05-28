#include <iostream>
#include <string.h>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 20005
#define INF 0x3f3f3f3f

using namespace std;

struct edge {
  int x, y, d;
  edge() {}
  edge(int X, int Y, int D): x(X), y(Y), d(D) {}
};
int par[MAX_N];
int T, N, M, R;
vector<edge> G;
void init() {
  for (int i = 0; i < N + M; i++) {
    par[i] = i;
  }
}
int find(int x) {
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  par[x] = y;
}
bool same(int x, int y) {
  return find(x) == find(y);
}
bool compare(edge a, edge b) {
  return a.d < b.d;
}
int kruscal() {
  init();
  sort(G.begin(), G.end(), compare);
  int res = 0;
  for (int i = 0; i < G.size(); i++) {
    edge e = G[i];
    int u = e.x, v = e.y, d = e.d;
    if (!same(u, v)) {
      res += d;
      unite(u, v);
    }
  }
  return res;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    G.clear();
    scanf("%d%d%d", &N, &M, &R);
    for (int i = 0; i < R; i++) {
      int x, y, d;
      scanf("%d%d%d", &x, &y, &d);
      G.push_back(edge(x, y + N, -d));
    }
    printf("%d\n", 10000 * (N + M) + kruscal());
  }
  return 0;
}
