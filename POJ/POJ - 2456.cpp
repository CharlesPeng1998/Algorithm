#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 1000000005

using namespace std;

const int maxn = 100005;
int N, C;
int x[maxn];

bool judge(int d) {
  int last = 0;
  for (int i = 1; i < C; i++) {
    int curr = last + 1;
    while (curr < N && x[curr] - x[last] < d) curr++;
    if (curr >= N) return false;
    last = curr;
  }
  return true;
}

int main() {
  scanf("%d%d", &N, &C);
  for (int i = 0; i < N; i++) scanf("%d", x + i);
  sort(x, x + N);
  int lb = 0, ub = INF;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (judge(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n", lb);
  return 0;
}
