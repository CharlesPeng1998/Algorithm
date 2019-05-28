#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#define MAX_N 10005

using namespace std;

typedef pair<int, int> P;
struct edge {
  int u, v;
  double cost;
  edge() {}
  edge(int U, int V, double C): u(U), v(V), cost(C) {}
};
vector<edge> G;
P cord[MAX_N];
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
  par[x] = y;
}
bool same(int x, int y) {
  return find(x) == find(y);
}
double get_dis(P a, P b) {
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double kruscal() {
  init();
  sort(G.begin(), G.end(), compare);
  double res = 0.0;
  for (int i = 0; i < G.size(); i++) {
    edge e = G[i];
    if (!same(e.u, e.v)) {
      res += e.cost;
      unite(e.u, e.v);
    }
  }
  return res;
}
int main() {
  scanf("%d%d", &N, &M);
  double total_cost = 0.0;
  for (int i = 1; i <= N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    cord[i] = make_pair(x, y);
  }
  for (int i = 0; i < M; i++) {
    int p, q;
    scanf("%d%d", &p, &q);
    double d = get_dis(cord[p], cord[q]);
    total_cost += d;
    G.push_back(edge(p, q, -d));
  }
  printf("%.3lf\n", total_cost + kruscal());
  return 0;
}
