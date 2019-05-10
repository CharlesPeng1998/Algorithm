#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;
const double eps = 1e-7;
int n, k;
double a[maxn], b[maxn];
double t[maxn];
double mid;

bool judge(double x) {
  for (int i = 0; i < n; i++) t[i] = a[i] - x * b[i];
  sort(t, t + n);
  double sum = 0.0;
  for (int i = k; i < n; i++) sum += t[i]; //从大到小选取n-k个
  if (sum > 0) return true;
  else return false;
}

int main() {
  while (scanf("%d%d", &n, &k)) {
    if (n == 0 && k == 0) break;
    for (int i = 0; i < n; i++) scanf("%lf", a + i);
    for (int i = 0; i < n; i++) scanf("%lf", b + i);
    double lb = 0.0, ub = 1.0;
    while (ub - lb > eps) {
      mid = (ub + lb) / 2;
      if (judge(mid)) lb = mid;
      else ub = mid;
    }
    printf("%.0f\n", mid * 100);
  }
  return 0;
}
