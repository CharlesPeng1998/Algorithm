#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 300005;
int n;
int a[maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int k = INF;
  for (int i = 1; i <= n; i++) {
    k = min(a[i] / max(i - 1, n - i), k);
  }
  cout << k << endl;;
  return 0;
}
