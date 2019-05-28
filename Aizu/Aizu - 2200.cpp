#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define MAX_N 205
#define DEBUG 0
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
int land[MAX_N][MAX_N];
int sea[MAX_N][MAX_N];
ll dp[1005][MAX_N]; //这个用long long， 递推过程中会处理INF，将导致int溢出
int z[1005];
int N, M, R;
void floyd() {
  for (int k = 1; k <= N; k ++) {
    for (int i = 1; i <= N; i ++) {
      for (int j = 1; j <= N; j ++) {
        land[i][j] = min(land[i][j], land[i][k] + land[k][j]);
        sea[i][j] = min(sea[i][j], sea[i][k] + sea[k][j]);
      }
    }
  }
}
int main() {
  while (scanf("%d%d", &N, &M)) {
    if (N == 0 && M == 0) break;
    memset(land, INF, sizeof land);
    memset(sea, INF, sizeof sea);
    memset(dp, INF, sizeof dp);
    for (int i = 1; i <= N; i ++) {
      land[i][i] = 0;
      sea[i][i] = 0;
    }
    int x, y, t;
    char sl[3];
    for  (int i = 0; i < M; i ++) {
      scanf("%d%d%d%s", &x, &y, &t, sl);
      if (!strcmp(sl, "L")) {
        land[x][y] = min(t, land[x][y]);
        land[y][x] = min(t, land[y][x]);
      }
      else if (!strcmp(sl, "S")) {
        sea[x][y] = min(t, sea[x][y]);
        sea[y][x] = min(t, sea[y][x]);
      }
    }
    scanf("%d", &R);
    for (int i = 1; i <= R; i ++) scanf("%d", z+i);
    floyd();
    dp[1][z[1]] = 0;
    for (int i = 1; i <= R; i ++) {
      for (int j = 1; j <= N; j ++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + land[z[i - 1]][z[i]]);
        for (int k = 1; k <= N; k ++) {
          dp[i][k] = min(dp[i][k], dp[i - 1][j] + land[z[i - 1]][j] + sea[j][k] + land[k][z[i]]);
        }
      }
    }
    ll res = INF;
    for (int i = 1; i <= N; i++) {
      if (dp[R][i] < res) res = dp[R][i];
    }
    printf("%lld\n", res);
  }
  return 0;
}
