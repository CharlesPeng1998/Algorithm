/*
贪心，似乎和二分查找没太大关系
按照w + s降序排列即可
证明如下：
考虑相邻的两个牛j和i，i在j的上面，
两个相邻牛交换位置不影响其他牛的风险值，
设sum为两头牛上面的牛体重总和，
risk[i] = sum -s[i], risk[j] = sum + w[i] -s[j],
交换位置后：
Risk[i] = sum + w[j] - s[i], Risk[j] = sum - s[j]

若交换前优于交换后，则有max(risk[i], risk[j]) < max(Risk[i], Risk[j])
而risk[j] > Risk[j],
所以Risk[i] > max(risk[i], risk[j])且Risk[i] > Risk[j]
所以有:
w[j] - s[i] > - s[i],
w[j] - s[i] > w[i] - s[j] ----->w[j] + s[j] > w[i] + s[i]!!!
w[j] - s[i] > - s[j]

综上若要交换前更优则需要满足w[j] > s[j] > w[i] + s[j]
即下面的更重 力量更大 符合直观认识
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG 0
#define INF 0x3f3f3f3f

using namespace std;

struct cow {
  int w;
  int s;
};

bool compare(cow a, cow b) {
  return a.w + a.s > b.w + b.s;
}

const int maxn = 50005;
cow c[maxn];
int N;

int main() {
  int sum = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &c[i].w, &c[i].s);
    sum += c[i].w;
  }
  sort(c, c + N, compare);
  int maxmum = 0x80808080;
  for (int i = 0; i < N; i++) {
    sum -= c[i].w;
    int risk = sum - c[i].s;
    maxmum = max(maxmum, risk);
  }
  printf("%d\n", maxmum);
  return 0;
}
