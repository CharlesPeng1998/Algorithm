#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int N;
int a[2][maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int min_pos = maxn, max_pos = -1;
  cin >> N;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        min_pos = min(min_pos, j);
        max_pos = max(max_pos, j);
      }
    }
  }
  int ans = 0;
  for (int i = min_pos; i < max_pos; i++) {
    if (a[0][i] && a[1][i]) {
      if (!a[0][i + 1] && !a[1][i + 1]) {
        ans++;
        a[0][i + 1] = a[1][i + 1] = 1;
      }
    }
    else if (a[0][i] && !a[0][i + 1]) {
      ans++;
      a[0][i + 1] = 1;
    }
    else if (a[1][i] && !a[1][i + 1]) {
      ans++;
      a[1][i + 1] = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
