#include <cstdio>
#include <iostream>
#include <algorithm>
#define DEBUG 1
#include <string.h>
#define MAX_N 105
#define INF 0x3f3f3f3f
#include <vector>
using namespace std;

// dp[i][j] = 前i个设备中最大宽带为j时的最小价格
int dp[MAX_N][1200];
int n;
int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    memset(dp, INF, sizeof dp);
    for (int i = 0; i < n; i++) {
      int m, b, p;
      scanf("%d", &m);
      if (i == 0) {
        for (int j =  0; j < m; j++) {
          scanf("%d%d", &b, &p);
          d[i][b] = p;
        }
      }
    }
  }
  return 0;
}
