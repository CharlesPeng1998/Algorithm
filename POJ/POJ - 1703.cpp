#include <iostream>
#include <string.h>
#include <cstdio>
#define MAXN 100005
#define MAXM 100005
using namespace std;

int T, N, M;
int par[2 * MAXN];

int find(int x) {
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

bool same(int x, int y) {
  return find(x) == find(y);
}

void unite(int x, int y) {
  int root_x = find(x);
  int root_y = find(y);
  if (root_x == root_y) return;
  else par[root_x] = root_y;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= 2 * N; i++) par[i] = i;
    char op[3]; int a, b;
    for (int i = 0; i < M; i++) {
      scanf("%s%d%d", op, &a, &b);
      if (strcmp(op, "D") == 0) {
        unite(a, b + N);
        unite(a + N, b);
      }
      else if (strcmp(op, "A") == 0) {
        if (same(a, b) || same(a + N, b + N)) printf("In the same gang.\n");
        else if (same(a, b + N) || same(a + N, b)) printf("In different gangs.\n");
        else printf("Not sure yet.\n");
      }
    }
  }
  return 0;
}
