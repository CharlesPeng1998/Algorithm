#include <bits/stdc++.h>
#define MAX_N 105
#define INF 0x3f3f3f3f
using namespace std;

int n, t;
int dp[MAX_N][MAX_N][MAX_N];
int a[MAX_N];
int main() {
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, INF, sizeof dp);
  dp[0][1][0] = a[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if (dp[i - 1][j + 3][k - 1] != INF) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + 3][k - 1]);
        if (dp[i - 1][j + 2][k] != INF) dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i - 1][j + 2][k] + (a[i]%2==0?a[i]/2:a[i]/2+1));
        if (j >= 1 && dp[i - 1][j - 1][k] != INF) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k] + a[i]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <=n; j++) {
        for (int k = 0; k <= n; k++) {
          if (dp[i][j][k] <= t) res = max(res, i + 1 - k);
        }
    }
  }
  cout << res << endl;
  return 0;
}
