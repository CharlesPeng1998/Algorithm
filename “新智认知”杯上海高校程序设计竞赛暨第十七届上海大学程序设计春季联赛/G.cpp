// 得注意数据范围
// int会溢出

#include <bits/stdc++.h>
#define MAX_N 200005

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m;
ll s;
ll val[MAX_N];
int degree[MAX_N];
struct edge {
  int to;
  int cost;
  edge() { }
  edge(int t, int c) {
    to = t;
    cost = c;
  }
};
vector<edge> G[MAX_N];
int main() {
  scanf("%d%d%lld", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    int x, y, r;
    scanf("%d%d%d", &x, &y, &r);
    G[x].push_back(edge(y, r));
    degree[y]++;
  }
  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (degree[i] == 0) que.push(i);
  }
  while (!que.empty()) {
    int u = que.front(); que.pop();
    for (int i = 0; i < G[u].size(); i ++) {
      val[G[u][i].to] = max(val[G[u][i].to], val[u] + G[u][i].cost);
      degree[G[u][i].to] --;
      if (degree[G[u][i].to] == 0) que.push(G[u][i].to);
    }
  }
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += val[i];
  }

	if(sum == 0) cout << -1 << endl;
	else cout << (s/sum) << endl;
  return 0;
}
