/*
这道题只是把数集做了一些改动
同样按照一般素数的定义进行筛出素数表+素数判别表
数据范围为六次方，所以可行
然后再跑一遍范围数集内所有数，是否含有两个素因子
结果同样用表记录
最后根据询问直接给出结果即可
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

const int maxn = 1000005;
bool notprime[maxn];
int fatCnt;
vector<int> factor;
int cnt[maxn];

void init() {
  memset(notprime, false, sizeof notprime);
  memset(cnt, 0, sizeof cnt);
  fatCnt = 0;
  notprime[1] = true;
  for (int i = 1; 4 * i + 1 < maxn; i++) {
    int j = 4 * i + 1;
    if (!notprime[j]) {
      fatCnt++;
      factor.push_back(j);
      if (j > maxn / j) continue;
      for (int k = j * j; k < maxn; k += j) notprime[k] = true;
    }
  }
  int curr_num = 0;
  for (int i = 1; 4 * i + 1 < maxn; i++) {
    int j = 4 * i + 1;
    bool flag = 0;
    for (int k = 0; k < fatCnt && factor[k] <= j/factor[k]; k++) {
      if (j % factor[k] == 0 && !notprime[j/factor[k]]) {
        flag = 1;
        break;
      }
    }
    if (flag) cnt[j] = ++curr_num;
    else cnt[j] = curr_num;
  }
}
int main() {
  init();
  int h;
  while (scanf("%d", &h)) {
    if (h == 0) break;
    printf("%d %d\n", h, cnt[h]);
  }
  return 0;
}
