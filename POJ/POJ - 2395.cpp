#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define MAX_N 2005
#define INF 0x3f3f3f3f

using namespace std;

struct edge {
  int u, v, cost;
  edge() {}
  edge(int x, int y, int c):u(x), v(y), cost(c) {}
};
vector<edge> G;
int par[MAX_N];
int N, M;

bool compare(edge a, edge b) {
  return a.cost < b.cost;
}
void init() {
  for (int i = 1; i <= N; i++) par[i] = i;
}
int find(int x) {
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  else par[x] = y;
}
bool same(int x, int y) {
  return find(x) == find(y);
}
int kruscal() {
  int res = 0;
  init();
  sort(G.begin(), G.end(), compare);
  for (int i = 0; i < G.size(); i++) {
    edge e = G[i];
    if (!same(e.u, e.v)) {
      res = max(res, e.cost);
      unite(e.u, e.v);
    }
  }
  return res;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    int A, B, L;
    scanf("%d%d%d", &A, &B, &L);
    G.push_back(edge(A, B, L));
  }
  printf("%d\n", kruscal());
  return 0;
}
