#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 100005;
int x[maxn];
int N;

int judge(int mid) {
  int num = n * (n - 1) / 2;
  if (num & 1) num = num / 2 + 1;
  else num /= 2;


}

int main() {
  while (~scanf("%d", &N)) {
    for (int i = 0; i < N; i++) scanf("%d", x + i);
    sort(x, x + N);
    int lb = 0, ub = INF;
    while (ub - lb > 1) {

    }
  }
  return 0;
}
