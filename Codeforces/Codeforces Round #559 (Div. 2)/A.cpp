#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string op;
int N;
int main() {
  cin >> N >> op;
  int ans = 0;
  int k = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (op[i] == '+') k += 1;
    else k -= 1;
    ans = max(ans, k);
  }
  cout << ans << endl;
  return 0;
}
