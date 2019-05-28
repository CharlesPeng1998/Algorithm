/*
二分查找
对于查找的子序列最大和判断函数judge(int x)写歪了好久：
方法是一个一个加，发现大于x了就记为一段，最后判断x <= M,
因为贪心地取每段尽可能接近x划分的段数小于等于M的话，必定可以划分M段使得每段之和不超过x
写歪原因如下：
1. 没有判断每个元素是否有可能大于x
2. 没处理好边界条件：curr = N - 1，如果curr == N - 1而total < x也要将段数加一
*/
#include <iostream>
#include <cstdio>
#define INF 1000000005
#define DEBUG 0

using  namespace std;

const int maxn = 100005;
int a[maxn];
int N, M;

bool judge(int x) {
  int curr = 0;
  int total = 0;
  int cnt = 0;
  while (curr < N) {
    if (a[curr] > x) return false;
    total += a[curr];
    if (total <= x && curr != N - 1) curr++;
    else if (total > x) {
      total = 0;
      cnt++;
    }
    else if (total <= x && curr == N - 1) {
      cnt++;
      break;
    }
  }
  return cnt <= M;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", a + i);
  }
  int lb = 0, ub = INF;
  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    if (judge(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
