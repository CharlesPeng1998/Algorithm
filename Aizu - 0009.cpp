#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;
bool notprime[maxn];
int num_prime[maxn];
int n;

void init() {
  memset(notprime, false, sizeof notprime);
  memset(num_prime, 0, sizeof num_prime);
  int curr = 0;
  notprime[0] = notprime[1] = true;
  for (int i = 2; i < maxn; i++) {
    if (!notprime[i]) {
      num_prime[i] = ++curr;
      if (i > maxn / i) continue;
      for (int j = i * i; j < maxn; j += i) notprime[j] = true;
    }
    else num_prime[i] = curr;
  }
}

int main() {
  init();
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}
