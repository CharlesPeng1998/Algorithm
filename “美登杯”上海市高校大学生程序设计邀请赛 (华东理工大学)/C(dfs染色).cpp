#include <bits/stdc++.h>
#define DEBUG 0

using namespace std;

const int maxn = 100005;
vector<int> G[maxn];
vector<int> color[maxn];
int vis[maxn];
int n, k;
int nColor;
map<vector<int>, int> mp;

void dfs(int u) {
  vis[u] = 1;
  color[u].push_back(nColor);
  for (int i = 0; i < G[u].size(); i++) {
    if (!vis[G[u][i]]) dfs(G[u][i]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; i ++) {
    for (int j = 1; j <= n; j++) G[j].clear();
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    nColor = 0;
    memset(vis, 0, sizeof vis);
    for (int j = 1; j <= n; j++) {
      if (!vis[j]) {
        nColor ++;
        dfs(j);
      }
    }
  }
  for (int i = 1; i <= n; i ++) {
    if (!mp.count(color[i])) mp[color[i]] = 1;
    else mp[color[i]] ++;
  }
  for (int i = 1; i <= n; i++) {
    cout << mp[color[i]] << endl;
  }
  return 0;
}
