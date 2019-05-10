#include <bits/stdc++.h>
#define MAX_N 100005
#define DEBUG 0
#define a first
#define b second
using namespace std;

typedef pair<int, long long> P;
int n, m;
P master[MAX_N];
int c[MAX_N];
P mp[MAX_N];
int id[MAX_N];
int vis[MAX_N];
stack<P> l;
stack<P> r;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1 ; i <= m; i++) {
    cin >> master[i].a >> master[i].b;
    mp[master[i].a] = master[i];
    id[master[i].a] = i;
  }
  for (int i = 1; i <= n; i++) cin >> c[i];
  sort(master + 1, master + m + 1);
  P curr = master[1];
  int max_l = master[1].a;
  l.push(curr);
  for (int i = master[1].a; i <= n; i++) {
    curr.b += c[i];
    if (curr.b < 0) break;
    max_l = max(max_l, i);
    if (!c[i]) {
      P p = mp[i];
      if (p.b > curr.b) {
        curr = p;
        l.push(curr);
      }
    }
  }
  curr = master[m];
  int max_r = master[m].a;
  r.push(curr);
  for (int i = master[m].a; i >= 1; i--) {
    curr.b += c[i];
    if (curr.b < 0) break;
    max_r = min(max_r, i);
    if (!c[i]) {
      P p = mp[i];
      if (p.b > curr.b) {
        curr = p;
        r.push(curr);
      }
    }
  }
  if (max_l + 1 < max_r) { // 注意这个不可行的判断条件 如果max_r == max_l + 1那还是可行的
    cout << -1 << endl;
  }
  else {
    int target = max_l;
    memset(vis, 0, sizeof vis);
    cout << target << endl;
    while (!l.empty()) {
      P p = l.top();
      l.pop();
      if (vis[id[p.a]]) continue;
      cout << id[p.a] << ' ';
      vis[id[p.a]] = 1;
    }
    while (!r.empty()) {
      P p = r.top();
      r.pop();
      if (vis[id[p.a]]) continue;
      cout << id[p.a] << ' ';
      vis[id[p.a]] = 1;
    }
    for (int i = 1; i <= m; i++) {
      if (vis[i]) continue;
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}
