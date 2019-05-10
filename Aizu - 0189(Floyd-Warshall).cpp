#include <bits/stdc++.h>
#define MAX_V 10
#define INF 0x3f3f3f3f
using namespace std;

int d[MAX_V][MAX_V];

int n;
int V;
int main() {
  while (scanf("%d", &n)) {
    if (n == 0) break;
    V = 0;
    memset(d, INF, sizeof d);
    int a, b, c;
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &a, &b, &c);
      d[a][b] = c; d[b][a] = c;
      V = max(V, a); V = max(V, b);
    }
    for (int i = 0; i <= V; i++) d[i][i] = 0;
    for (int k = 0; k <= V; k++) {
      for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= V; j++) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    int id, ans = INF;
    for (int j = 0; j <= V; j++) {
      int dis = 0;
      for (int i = 0; i <= V; i++) dis += d[j][i];
      if (dis < ans) {
        id = j; ans = dis;
      }
    }
    printf("%d %d\n", id, ans);
  }
  return 0;
}
