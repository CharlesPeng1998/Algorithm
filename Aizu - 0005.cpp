#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a, b;

ll gcd(ll a, ll b) {
  ll r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> a >> b) {
    cout << gcd(a, b) << ' ' << lcm(a, b) << endl;
  }
  return 0;
}
