#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

typedef long long ll;
const int maxn = 1100000;
ll factor[100][2];
int fatCnt;
int prime[maxn + 1];
int x;
int max_len;
int len_num;

void getPrime() {
  memset(prime, 0, sizeof prime);
  for (int i = 2; i <= maxn; i++) {
    if (!prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0] && prime[j] <= maxn / i; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}

int getFactors(ll x) {
  fatCnt = 0;
  ll tmp = x;
  for (int i = 1; prime[i] <= tmp / prime[i]; i++) {
    factor[fatCnt][1] = 0;
    if (tmp % prime[i] == 0) {
      factor[fatCnt][0] = prime[i];
      while (tmp % prime[i] == 0) {
        factor[fatCnt][1]++;
        tmp /= prime[i];
      }
      fatCnt++;
    }
  }
  if (tmp != 1) {
    factor[fatCnt][0] = tmp;
    factor[fatCnt++][1] = 1;
  }
  return fatCnt;
}

void dfs(int x, int fatCnt) {
  if (x == 1) len_num++;
  for (int i = 0; i < fatCnt; i++) {
    if (factor[i][1] == 0) continue;
    factor[i][1]--;
    dfs(x / factor[i][0], fatCnt);
    factor[i][1]++;
  }
}

int main() {
  getPrime();
  while (scanf("%d", &x) != EOF) {
    int fatCnt = getFactors(x);
    max_len = 0;
    for (int i = 0; i < fatCnt; i++) {
      max_len += factor[i][1];
    }
    len_num = 0;
    dfs(x, fatCnt);
    printf("%d %d\n", max_len, len_num);
  }
  return 0;
}
