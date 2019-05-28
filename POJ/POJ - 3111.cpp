#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct T {
  double val;
  int id;
};

const int maxn = 100005;
const double eps = 1e-7;
int v[maxn], w[maxn];
int n, k;
T t[maxn];
int res[maxn];

bool cmp(T a, T b) {
  return a.val > b.val;
}

bool judge(double x) {
  for (int i = 0; i < n; i++) {
    t[i].val = v[i] - x * w[i];
    t[i].id = i;
  }
  sort(t, t + n, cmp);
  double sum = 0.0;
  for (int i = 0; i < k; i++) {
    sum += t[i].val;
    res[i] = t[i].id;
  }
  if (sum > 0.0) return true;
  else return false;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d%d", v + i, w + i);
  double lb = 0.0, ub = 1000006.0;
  while (ub - lb > eps) {
    double mid = (ub + lb) / 2;
    if (judge(mid)) lb = mid;
    else ub = mid;
  }
  for (int i = 0; i < k; i++) {
    printf("%d ", res[i] + 1);
  }
  printf("\n");
  return 0;
}
