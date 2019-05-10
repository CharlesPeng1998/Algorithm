// 快速幂水题
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
int Z, M, H;

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

int main () {
  scanf("%d", &Z);
  while (Z--) {
    ll res = 0;
    scanf("%d", &M);
    scanf("%d", &H);
    for (int i = 0; i < H; i++) {
      ll A, B;
      scanf("%lld%lld", &A, &B);
      res = (res + pow_mod(A, B, M)) % M;
    }
    printf("%lld\n", res);
  }
  return 0;
}
