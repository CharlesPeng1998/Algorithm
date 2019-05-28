#include <bits/stdc++.h>
#define MAX_N 200005
using namespace std;

typedef pair<int, int> P;
int n, k;
P a[MAX_N];
int l[MAX_N];
int r[MAX_N];
int team[MAX_N];
priority_queue<P> que;
int main() {
  cin >> n >> k;
  memset(team, -1, sizeof team);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
    if (i == 0) l[i] = -1;
    else l[i] = i - 1;
    if (i == n - 1) r[i] = -1;
    else r[i] = i + 1;
    que.push(a[i]);
  }
  int t = 1;
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    if (team[p.second] != -1) continue;
    team[p.second] = t;
    if (r[p.second] != -1) l[r[p.second]] = l[p.second];
    if (l[p.second] != -1) r[l[p.second]] = r[p.second];
    int nxt = r[p.second];
    for(int i = 0; i < k; i++) {
      if (nxt == -1) break;
      team[nxt] = t;
      if (r[nxt] != -1) l[r[nxt]] = l[nxt];
      if (l[nxt] != -1) r[l[nxt]] = r[nxt];
      nxt = r[nxt];
    }
    nxt = l[p.second];
    for(int i = 0; i < k; i++) {
      if (nxt == -1) break;
      team[nxt] = t;
      if (r[nxt] != -1) l[r[nxt]] = l[nxt];
      if (l[nxt] != -1) r[l[nxt]] = r[nxt];
      nxt = l[nxt];
    }
    t = (t == 1? 2 : 1);
  }
  for (int i = 0; i < n; i++) printf("%d", team[i]);
  printf("\n");
  return 0;
}
