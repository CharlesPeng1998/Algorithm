/*
二分查找
对于每个查找的x判断能否在x分钟以内全部晾干。
如果使用了烘干机，每分钟减少k，我们可以视作使用烘干机的同时也在风干，
即烘干机使得减少(k-1)。
判断的过程我们这么处理，将a[]中的每一个元素减去给定x，即先全部进行风干
此时大于0的元素即需要进行烘干机，每个元素烘干需要的时间为ceil(a[i] - x)/(k -1)。
若烘干时间之和大于x即无法完成。

需要注意的地方是k==1的情形，这种条件下相当于没有烘干机，满足的x为a[]中的最大值。
如果对k==1的情形使用上述判断条件，将出现除0 runtime error
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define DEBUG 1

using namespace std;

typedef long long ll;
const int maxn = 100005;
int a[maxn];
int N, K;

bool judge(int x) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] > x) {
      cnt += (a[i] - x) / K;
      if ((a[i] - x) % K) cnt++;
      if (cnt > x) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &N);
  int inf = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", a + i);
    inf = max(inf, a[i]);
  }
  scanf("%d", &K);
  int lb = 0, ub = inf;
  K--;
  if (K == 0) {
    printf("%d\n", inf);
  }
  else {
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (judge(mid)) ub = mid;
      else lb = mid;
    }
    printf("%d\n", ub);
  }
  return 0;
}
