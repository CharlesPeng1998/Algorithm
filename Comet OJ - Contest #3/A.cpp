#include <bits/stdc++.h>
#define DEBUG 1

using namespace std;

typedef long long ll;
const int maxn = 506;
int N, K;
ll a[maxn];
ll b[maxn * maxn];
ll res;

bool compare(ll a, ll b) {
  return a > b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> a[i];
  int idx = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      b[idx++] = a[i] + a[j];
    }
  }
  res = 0;
  sort(b, b + N * (N - 1) / 2, compare);
  for (int i = 0; i < K; i++) res += b[i];
  cout << res << endl;
  return 0;
}
