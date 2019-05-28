#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
#define DEBUG 1
#define MAX_N 105
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> P;
int G[MAX_N][MAX_N];
int N;
int mincost[MAX_N];

int prim() {
  memset(mincost, INF, sizeof mincost);
  int res = 0;
  mincost[0] = 0;
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(make_pair(0,0));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    if (mincost[p.second] < p.first) continue;
    res += p.first;
    for (int i = 0; i < N; i++) {
      if (mincost[i] > G[p.second][i]) {
        mincost[i] = G[p.second][i];
        que.push(make_pair(mincost[i], i));
      }
    }
  }
  return res;
}
int main() {
  while (scanf("%d", &N) != EOF) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &G[i][j]);
      }
    }
    printf("%d\n", prim());
  }
  return 0;
}
