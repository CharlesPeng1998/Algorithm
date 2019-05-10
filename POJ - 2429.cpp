#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
const int S = 8;
ll factor[200];
map<ll, ll> mp;
int tol;
ll GCD, LCM;
ll a, b;
ll F[200];
ll s;

ll mult_mod(ll a, ll b, ll c) {
  a %= c;
  b %= c;
  ll ret = 0;
  ll tmp = a;
  while (b) {
    if (b & 1) {
      ret += tmp;
      if (ret > c) ret -= c;
    }
    tmp <<= 1;
    if (tmp > c) tmp -= c;
    b >>= 1;
  }
  return ret;
}

ll pow_mod(ll a, ll n, ll mod) {
  ll ret = 1;
  ll temp = a % mod;
  while (n) {
    if (n & 1) ret = mult_mod(ret, temp, mod);
    temp = mult_mod(temp, temp, mod);
    n >>= 1;
  }
  return ret;
}

bool check(ll a, ll n, ll x, ll t) {
  ll ret = pow_mod(a, x, n);
  ll last = ret;
  for (int i = 1; i <= t; i++) {
    ret = mult_mod(ret, ret, n);
    if (ret == 1 && last != 1 && last != n - 1) return true;
    last = ret;
  }
  if (ret != 1) return true;
  else return false;
}

bool Miller_Rabin(ll n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if ((n & 1) == 0) return false;
  ll x = n - 1;
  ll t = 0;
  while ((x & 1) == 0) {x >>= 1; t++;}
  srand(time(NULL));
  for (int i = 0; i < S; i++) {
    ll a = rand() % (n - 1) + 1;
    if (check(a, n, x, t)) return false;
  }
  return true;
}

ll gcd(ll a, ll b) {
  ll t;
  while (b) {
    t = a;
    a = b;
    b = t % b;
  }
  if (a >= 0) return a;
  else return -a;
}

ll pollard_rho(ll x, ll c) {
  ll i = 1, k = 2;
  srand(time(NULL));
  ll x0 = rand() % (x - 1) + 1;
  ll y = x0;
  while (1) {
    i ++;
    x0 = (mult_mod(x0, x0, x) + c) % x;
    ll d = gcd(y - x0, x);
    if (d != 1 && d != x) return d;
    if (y == x0) return x;
    if (i == k) {y = x0; k += k;}
  }
}

void findfac(ll n, int k) {
  if (n == 1) return;
  if (Miller_Rabin(n)) {
    factor[tol++] = n;
    if (mp.count(n)) {
      mp[n] *= n;
    }
    else mp[n] = n;
    return;
  }
  ll p = n;
  int c = k;
  while (p >= n) p = pollard_rho(p, c--);
  findfac(p, k);
  findfac(n / p, k);
}

void dfs(int n, int cnt, ll res, ll m) {
  if (n > cnt || res > m) return;
  a = max(a, res);
  if (res * F[n] <= m) dfs(n + 1, cnt, res * F[n], m);
  dfs(n + 1, cnt, res, m);
}

int main() {
  while (cin >> GCD >> LCM) {
    tol = 0;
    mp.clear();
    s = LCM / GCD;
    findfac(s, 107);
    int cnt = 0;
    for (map<ll, ll>::iterator iter = mp.begin(); iter != mp.end(); iter++)
      F[cnt++] = (*iter).second;
    ll m = (ll)sqrt(s + 0.0); // 对long long使用sqrt()的正确方式
    a = 1;
    dfs(0, cnt, 1, m);
    b = s / a;
    cout << a * GCD << ' ' << b * GCD << endl;
  }
  return 0;
}
