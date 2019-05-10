/*
二分查找
对于每个d的判断条件C(d):任意两个石头之间距离不小于d
要满足的话其实只需要相邻两个石头距离不小于d即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 1000000005

using namespace std;

const int maxn = 50005;
int L, N, M;
int x[maxn];

bool judge(int d) {
  int curr = 0;
  int r = M;
  int nxt = curr + 1;
  while (nxt <= N + 1) {
    if (x[nxt] - x[curr] < d) {
      if (r <= 0) return false;
      else {
        r--;
        nxt++;
      }
    }
    else {
      curr = nxt;
      nxt = curr + 1;
    }
  }
  return true;
}

int main() {
  scanf("%d%d%d", &L, &N, &M);
  x[0] = 0;
  for (int i = 1; i <= N; i++) scanf("%d", x + i);
  x[N + 1] = L;
  sort(x, x + N + 2);
  int lb = 0, ub = INF;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (judge(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n", lb);

  return 0;
}
