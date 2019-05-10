#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
#include <string.h>
#include <vector>
#include <algorithm>
#define DEBUG 0
#define MAX_N 505
using namespace std;

struct edge {
  int from;
  int to;
  int cost;
  edge() {};
  edge(int f, int t, int c) {
    from = f;
    to = t;
    cost = c;
  }
};
int F, N, M, W;
vector<edge> G;
int d[MAX_N];
bool find_negative_loop() {
  memset(d, 0, sizeof d);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < int(G.size()); j++) {
      edge e = G[j];
      if(d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i == N) return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d", &F);
  while (F --) {
    scanf("%d%d%d", &N, &M, &W);
    G.clear();
    int S, E, T;
    for (int i = 0; i < M; i++) {
      scanf("%d%d%d", &S, &E, &T);
      G.push_back(edge(S, E, T));
      G.push_back(edge(E, S, T));
    }
    for (int i = 0; i < W; i++) {
      scanf("%d%d%d", &S, &E, &T);
      G.push_back(edge(S, E, -T));
    }
    if (find_negative_loop()) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
