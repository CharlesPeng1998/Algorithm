#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;

int n, q;
int p[MAX_N];
int pre[MAX_N];
int s[MAX_N];
int vis[MAX_N]; // 记录结点是否已被使用
int cir[MAX_N]; // cir[i] = j 第i个节点属于环j
int stat[MAX_N]; // stat[i] 环i中含有多少个反面牌
int cnt[MAX_N]; // cnt[i] 环i中的节点个数（正+反）
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) pre[p[i]] = i;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    int node = i;
    int tmp = 0; //记录当前环中有多少段链
    while (!vis[node]) {
      if (!s[node] && s[pre[node]]) tmp += 1;
      vis[node] = 1;
      cir[node] = i;
      cnt[i] ++;
      stat[i] += s[node];
      node = p[node];
    }
    if (tmp) ans += tmp;
    else if (stat[i] == 0) ans += 1; //完整环
  }
  int op, x;
  for (int i = 0; i < q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      if (!s[x]) {
        if ((s[p[x]] && s[pre[x]]) || cnt[cir[x]] == 1) ans -= 1;
        if (!s[p[x]] && !s[pre[x]] && stat[cir[x]]) ans += 1;
        stat[cir[x]]++;
      }
      else {
        if (s[p[x]] && s[pre[x]]) ans++;
        if (!s[p[x]] && !s[pre[x]] && stat[cir[x]] > 1) ans--;
        stat[cir[x]]--;
      }
      s[x] = 1 - s[x];
    }
    else {
      cout << ans << endl;
    }
  }
  return 0;
}
