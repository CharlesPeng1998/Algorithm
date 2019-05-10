#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define MAX_V 305
#define INF 0x3f3f3f3f
using namespace std;

int G[MAX_V][MAX_V];
int d[MAX_V];
int used[MAX_V];
int N, M;
int movie[MAX_V];

int dijkstra(int s) {
  memset(d, INF, sizeof d);
  memset(used, 0, sizeof used);
  d[s] = 0;
  while (true) {
    int v = -1;
    for (int i = 1; i <= N; i++) {
      if (!used[i] && (v == -1 || d[i] < d[v])) v = i;
    }
    if (v == -1) break;
    used[v] = 1;
    for (int i = 1; i <= N; i++) {
      if (G[v][i] != INF) {
        d[i] = min(d[i], d[v] + G[v][i]);
      }
    }
  }
  int total = 0;
  for (int i = 1; i <= N; i++) total += d[i];
  return total;
}
int main() {
  scanf("%d%d", &N, &M);
  memset(G, INF, sizeof G);
  for (int i = 0; i < M; i++) {
    int mi;
    scanf("%d", &mi);
    for (int j = 0; j < mi; j++) scanf("%d", movie + j);
    for (int j = 0; j < mi; j++) {
      for (int k = 0; k < mi; k++) {
        if (j == k) G[movie[j]][movie[k]] = 0;
        else G[movie[j]][movie[k]] = 1;
      }
    }
  }
  float res = float(dijkstra(1)) / (N - 1);
  for (int i = 2; i <= N; i++) {
    float shortest = float(dijkstra(i)) / (N - 1);
    if (shortest < res) res = shortest;
  }
  printf("%d\n", int(res * 100));
  return 0;
}
