#include <iostream>
#include <cstdio>
#include <cmath>
#define INF 100005

using namespace std;

typedef long long ll;
ll N, K;
double cable[10005];

bool judge(double x) {
  ll cnt = 0;
  for (int i = 0 ; i < N; i++) {
    cnt += ll(cable[i] / x);
  }
  return cnt >= K;
}

int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%lf", cable + i);
  double lb = 0, ub = INF;
  // for (int i = 0; i < 100; i++) {
  //   double mid = (lb + ub) / 2;
  //   if (judge(mid)) lb = mid;
  //   else ub = mid;
  // }
  while (ub - lb > 0.0001) {
    double mid = (lb + ub) / 2;
    if (judge(mid)) lb = mid;
    else ub = mid;
  }
  printf("%.2f\n", floor(ub * 100) / 100);
  /*
  这里为什么用floor()?
  如果直接.2f输出，第三位小数将四舍五入，而我们需要直接舍去
  */
  return 0;
}
