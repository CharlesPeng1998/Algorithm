#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
int main() {
  cin >> n >> m;
  ll max_k, min_k = 0;
  max_k = (ll)(n - m + 1) * (n - m) / 2;
  int avg = n / m, r = n % m;
  for (int i = 0; i < r; i++) {
    min_k += (ll)(avg + 1) * avg / 2;
  }
  for (int i = r; i < m; i++) {
    min_k += (ll)avg * (avg - 1) / 2;
  }
  cout << min_k << ' ' << max_k;
  return 0;
}
