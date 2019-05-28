/*
Miller_Rabin素数判定 + 快速幂
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <time.h>

typedef long long ll;
const int maxn = 1000005;
const int S = 8;
int p, a;
bool notprime[maxn];

void init() {
  memset(notprime, 0, sizeof notprime);
  notprime[0] = notprime[1] = true;
  for (int i = 2; i < maxn; i++) {
    if (!notprime[i]) {
      if (i > maxn / i) continue;
      for (int j = i * i; j < maxn; j += i) notprime[j] = true;
    }
  }
}

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

int main() {
  init();
  while (scanf("%d%d", &p, &a)) {
    if (p == 0 && a == 0) break;
    bool prime = true;
    if (p <= 1000000) {
      if (notprime[p]) prime = false;
    }
    else {
      if (!Miller_Rabin(p)) prime = false;
    }
    if (prime) printf("no\n");
    else {
      if (pow_mod(a, p, p) == a) printf("yes\n");
      else printf("no\n");
    }
  }
  return 0;
}
