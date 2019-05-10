#include <bits/stdc++.h>
#define MAX_N 100005

using namespace std;
typedef long long ll;
int n, t;
ll num[MAX_N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    num[a]++;
  }
  ll res = 0;
  for (int i = 0; i < MAX_N; i++) {
    int dis = t - i;
    if (dis < i) continue;
    else if (dis == i) {
      res += num[i] * (num[i] - 1) / 2;
    }
    else res += num[i] * num[dis];
  }
  cout << res << endl;
  return 0;
}
