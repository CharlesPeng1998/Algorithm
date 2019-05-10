#include <bits/stdc++.h>
#define DEBUG 0
const int MAX_N = 100000;

using namespace std;

typedef long long ll;
int prime[MAX_N + 1];
ll l, r;
vector<ll> a;
vector<ll> b;
int vis[MAX_N];
void getPrime() {
  memset(prime, 0, sizeof prime);
  for (int i = 2; i <= MAX_N; i++) {
    if (!prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0] && prime[j] <= MAX_N / i; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  getPrime();
  cin >> l >> r;
  memset(vis, 0, sizeof vis);
  for (int i = 1; (ll)prime[i] * prime[i] <= r; i++) {
    ll p = prime[i];
    ll s = max((ll)p * p, l);
    for (ll j = s + (p - s % p) % p; j <= r; j+=p) {
      if (!vis[j - l]) vis[j - l] = p;
      else vis[j - l] = -1;
    }
  }
  for (ll i = l; i <= r; i++) {
    if (vis[i - l] > 1) {
      ll x = i / vis[i - l];
      if (x == vis[i - l] || x % vis[i - l] != 0) {
        a.push_back(vis[i - l]);
        b.push_back(x);
      }
    }
  }
  cout << a.size() << endl;
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] * b[i] << ' ' << a[i] << ' ' << b[i] << endl;
  }
  return 0;
}
