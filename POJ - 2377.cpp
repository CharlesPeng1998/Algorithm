#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define  MAX_N 1005
#define MAX_M 20005
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> P;
struct edge {
  int u, v, cost;
  edge() {}
  edge(int f, int t, int c): u(f), v(t), cost(c) {}
};
vector<edge> G;
int N, M;
int par[MAX_N];

void init() {
  for (int i = 1; i <= N; i++) {
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
  else par[x] = y;
}
bool same(int x, int y) {
  return find(x) == find(y);
}
bool compare(edge a, edge b) {
  return a.cost < b.cost;
}
int kruscal() {
  init();
  int cnt = 0;
  int res = 0;
  sort(G.begin(), G.end(), compare);
  for (int i = 0; i < M; i++) {
    edge e = G[i];
    int u = e.u, v = e.v;
    if (!same(u, v)) {
      cnt++;
      res += e.cost;
      unite(u, v);
    }
  }
  if (cnt != N - 1) return -1;
  else return res;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    G.push_back(edge(A, B, -C));
  }
  int ans = kruscal();
  if (ans != -1) ans *= -1;
  printf("%d\n", ans); 
  return 0;
}
