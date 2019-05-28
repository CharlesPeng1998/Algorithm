#include <iostream>
#include <string.h>
#include <cstdio>
#define MAXN 100005
#define MAXQ 100005
using namespace std;

typedef long long ll;
int N, Q;
int par[MAXN];
int mark[MAXN];
ll res; // 这题最终结果可达10^10 爆int

void find(int x) {
  if (mark[x]) {
    res += x;
    return;
  }
  else find(par[x]);
}

int main() {
  while (scanf("%d%d", &N, &Q)) {
    if (N == 0 && Q == 0) break;
    memset(mark, 0, sizeof mark);
    res = 0;
    par[1] = 1;
    mark[1] = 1;
    for (int i = 2; i <= N; i++) {
      scanf("%d", &par[i]);
    }
    char op[3]; int v;
    for (int i = 1; i <= Q; i++){
      scanf("%s%d", op, &v);
      if (strcmp(op, "M") == 0) mark[v] = 1;
      else if (strcmp(op, "Q") == 0) {
        find(v);
      }
    }
    cout << res <<endl;
  }
  return 0;
}
