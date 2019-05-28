#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int a[101];
int n;
int temp[3];
int D[3];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  temp[0] = (a[0] + a[n - 1]) / 2;
  temp[1] = a[0];
  temp[2] = a[n - 1];
  D[0] = temp[0] - a[0];
  D[1] = a[n - 1] - a[0];
  D[2] = a[n - 1] - a[0];
  int res = INF;
  int Flag = 0;
  for (int i = 0; i < 3; i++) {
    int flag = 1;
    int d = D[i];
    int t = temp[i];
    for (int j = 0; j < n; j++) {
      if (!(a[j] == t || a[j] + d == t || a[j] - d == t)) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      Flag = 1; res = min(res, d);
    }
  }
  if (Flag) cout << res << endl;
  else cout << -1 << endl;
  return 0;
}
