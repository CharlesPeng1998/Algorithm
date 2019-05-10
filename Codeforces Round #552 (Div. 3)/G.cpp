#include <bits/stdc++.h>
#define MAX_A 10000005
#define INF 0x7fffffffffffffffLL
using namespace std;

typedef long long ll;
struct A {
  int pos;
  int cnt = 0;
};
A a[MAX_A];
int n;
ll min_lcm = INF;
pair<int, int> ans;

ll gcd(ll x1, ll x2) {
  ll r = x1 % x2;
  while (r) {
    x1 = x2;
    x2 = r;
    r = x1 % x2;
  }
  return x2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (a[x].cnt == 0) {
      a[x].pos = i;
      a[x].cnt++;
    }
    else if (a[x].cnt == 1) {
      if (x < min_lcm) {
        min_lcm = x;
        ans = make_pair(a[x].pos, i);
      }
      a[x].cnt++;
    }
  }
  for (int d = 1; d < MAX_A; d++) {
    // int x1 = 0;
    ll x1 = 0;
    for (int x2 = d; x2 < MAX_A; x2 += d) {
      if (!a[x2].cnt) continue;
      if (!x1) x1 = x2;
      else {
        if (gcd(x1, x2) == d) {
          ll tmp = x2 / d * x1; //如果x1 x2都是int，运算过程中会爆int，导致赋值结果错误
          if (tmp < min_lcm) {
            min_lcm = tmp;
            ans = make_pair(a[x1].pos, a[x2].pos);
          }
        }
        break;
      }
    }
  }
  if (ans.first > ans.second) swap(ans.first, ans.second);
  cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
  return 0;
}
