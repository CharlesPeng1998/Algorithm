#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

typedef long long ll;
const int max_n = 1000005;
bool notprime[max_n];
int n;
ll a[max_n];
void init() {
  memset(notprime, false, sizeof notprime);
  notprime[0] = notprime[1] = true;
  for (int i = 2; i < max_n; i++) {
    if (!notprime[i]) {
      if (i > max_n / i) continue;
      for (int j = i * i; j < max_n; j += i) notprime[j] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int root = int(sqrt(a[i]));
    if ((ll)root * root != a[i]) cout << "NO" << endl;
    else if (notprime[root]) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
  return 0;
}
