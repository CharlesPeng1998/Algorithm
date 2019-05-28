#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#define INF 0x3f3f3f3f
#define MAX_N 1005
using namespace std;

typedef pair<int, int> P;
struct Node {
  int v;
  int f;
  int g;
  friend bool operator<(Node a, Node b) {
    return a.f > b.f || (a.f == b.f && a.g > b.g); // 这个序开始写错了，导致了无限MLE
  }
  Node() {}
  Node(int v, int f, int g):v(v), f(f), g(g) {}
};
struct Edge {
  int to;
  int cost;
  Edge() {}
  Edge(int t, int c):to(t), cost(c) {}
};
vector<Edge> G[MAX_N];
vector<Edge> anti_G[MAX_N];
int dis[MAX_N];
int vis[MAX_N];
int time[MAX_N];
int N, M;
int S, T, K;

void dijkstra(int s) {
  memset(dis, INF, sizeof dis);
  dis[s] = 0;
  while (true) {
    int v = -1;
    for (int i = 1; i <= N; i++) {
      if (!vis[i] && (v == -1 || dis[i] < dis[v])) v = i;
    }
    if (v == -1) break;
    vis[v] = 1;
    for (int i = 0; i < anti_G[v].size(); i++) {
      Edge e = anti_G[v][i];
      dis[e.to] = min(dis[e.to], dis[v] + e.cost);
    }
  }
}

int A_star(int s, int t) {
  priority_queue<Node> que;
  if (dis[s] == INF) return -1;
  if (s == t) K++;
  que.push(Node(s, dis[s], 0));
  while (!que.empty()) {
    Node n = que.top();
    que.pop();
    int u = n.v;
    time[u]++;
    if (time[u] == K && u == t) return n.g;
    if (time[u] > K) continue; // 如果一个点跑了K次就不用展开它了
    for (int i = 0; i < G[u].size(); i++) {
      Edge e = G[u][i];
      Node nn;
      nn.v = e.to;
      nn.g = n.g + e.cost;
      nn.f = nn.g + dis[e.to];
      que.push(nn);
    }
  }
  return -1;
}
int main() {
  scanf("%d%d", &N, &M);
  int A, B, T;
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &A, &B, &T);
    G[A].push_back(Edge(B, T));
    anti_G[B].push_back(Edge(A,T));
  }
  scanf("%d%d%d", &S, &T, &K);
  dijkstra(T);
  cout << A_star(S, T) << endl;

  return 0;
}
