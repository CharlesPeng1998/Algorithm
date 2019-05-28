#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#define MAX_N 1005
#define MAX_M 10005
#define INF 0x3f3f3f3f

using namespace std;

int N, ML, MD;
int AL[MAX_M], BL[MAX_M], DL[MAX_M];
int AD[MAX_M], BD[MAX_M], DD[MAX_M];
int dis[MAX_N];
bool updated;

void update(int &x, int y) {
  if (x > y) {
    x = y;
    updated = 1;
  }
}
void bellmanford() {
  for (int i = 0; i <= N; i++) {
    updated = 0;
    for (int i = 0; i + 1 < N; i++) {
      update(dis[i], dis[i + 1]);
    }
    for (int i = 0; i < ML; i++) {
      update(dis[BL[i] - 1], dis[AL[i] - 1] + DL[i]);
    }
    for (int i = 0; i < MD; i++) {
      update(dis[AD[i] - 1], dis[BD[i] - 1] - DD[i]);
    }
  }
}
int main() {
  scanf("%d%d%d", &N, &ML, &MD);
  for (int i = 0; i < ML; i++) scanf("%d%d%d", &AL[i], &BL[i], &DL[i]);
  for (int i = 0; i < MD; i++) scanf("%d%d%d", &AD[i], &BD[i], &DD[i]);
  memset(dis, 0, sizeof dis);
  bellmanford();
  if (updated) {
    printf("-1\n");
    return 0;
  }
  memset(dis, INF, sizeof dis);
  dis[0] = 0;
  bellmanford();
  int res = dis[N - 1];
  if (res == INF) printf("-2\n");
  else printf("%d\n", res);
  return 0;
}
