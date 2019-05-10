// 如果下一个滚动骰子(*)为0，继续轮到下一个
// 输出(*)的时候没有考虑到这个
#include <bits/stdc++.h>

using namespace std;
int c[15];
int n;
string s;
int T;
int main() {
  T = 1;
  while (cin >> n) {
    if (n == 0) break;
    if (T != 1) printf("\n");
    memset(c, 0, sizeof c);
    cin >> s;
    for (int i = 1; i <= n; i++) c[i] = 3;
    int idx = 0;
    int p = 1;
    bool win = 0;
    int winner;
    while (idx < s.length()) {
      for (int i = 1; i <=n; i++) {
        if (c[i] + c[0] == n * 3) {
          win = 1;
          winner = i;
          break;
        }
      }
      if (win) break;
      int roll;
      if (c[p] == 0) {
        p = (p == n)? 1 : p + 1;
        continue;
      }
      else if (c[p] >= 3) {
        roll = 3;
      }
      else roll = c[p];
      if (s.length() - idx < roll) break;
      for (int i = idx; i < idx + roll; i++) {
        if (s[i] == 'L') {
          int nxt = (p == n)? 1 : p + 1;
          c[nxt]++;
          c[p]--;
        }
        else if (s[i] == 'R') {
          int nxt = (p == 1)? n : p - 1;
          c[nxt]++;
          c[p]--;
        }
        else if (s[i] == 'C') {
          c[0]++;
          c[p]--;
        }
      }
      p = (p == n)? 1 : p + 1;
      while (c[p] == 0) p = (p == n)? 1 : p + 1;
      idx += roll;
    }
    if (win) {
      printf("Game %d:\n", T);
      for (int i = 1; i <= n; i++) {
        if (i == winner) {
          printf("Player %d:%d(W)\n", i, c[i]);
        }
        else printf("Player %d:%d\n", i, c[i]);
      }
      printf("Center:%d\n", c[0]);
    }
    else {
      printf("Game %d:\n", T);
      for (int i = 1; i <= n; i++) {
        if (i == p) {
          printf("Player %d:%d(*)\n", i, c[i]);
        }
        else printf("Player %d:%d\n", i, c[i]);
      }
      printf("Center:%d\n", c[0]);
    }
    T++;
  }
  return 0;
}
