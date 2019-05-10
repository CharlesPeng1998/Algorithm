#include <bits/stdc++.h>
#define MAX_N 200005
#define MAX_K 2005
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int, int> P;
int n, m, k;
int a[MAX_N];
int dp[MAX_K];
P offer[MAX_N];
int sum[MAX_K];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d%d", &offer[i].first, &offer[i].second);
  offer[m] = make_pair(1, 0);
  sort(a, a + n);
  sum[0] = a[0];
  for (int i = 1; i < k; i++) sum[i] = sum[i - 1] + a[i];
  memset(dp, INF, sizeof dp);
  dp[0] = 0;
  for (int i = 0; i <= k; i++) {
    for(int j = 0; j <= m; j++) {
      int x = offer[j].first;
      int y = offer[j].second;
      dp[i + x] = min(dp[i + x], dp[i] + sum[i + x - 1] - sum[i + x - 1 - (x - y)]);
    }
  }
  cout << dp[k] << endl;
  return 0;
}
