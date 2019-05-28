#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define DEBUG 0
using namespace std;

int food[3];
int week[7] = {0, 0, 1, 2, 0, 2, 1};

int min(int a, int b, int c) {
  int res = a < b? a : b;
  return res < c? res : c;
}
int main() {
  for (int i = 0; i < 3; i++) cin >> food[i];
  int week_num = min(food[0] / 3, food[1] / 2, food[2] / 2);
  int res = week_num * 7;
  food[0] -= week_num * 3;
  food[1] -= week_num * 2;
  food[2] -= week_num * 2;
  int d = 0;
  for (int i = 0; i < 7; i++) {
    int a = food[0];
    int b = food[1];
    int c = food[2];
    #if DEBUG
    cout << "Start from:" << i << endl;
    cout << a <<' '<< b <<' '<< c << endl;
    #endif
    int days = 0;
    for (int j = i; ; j = (j + 1) % 7) {
      bool flag = 0;
      if (week[j] == 0 && a > 0) {
        flag  = 1;
        days ++;
        a --;
        continue;
      }
      if (week[j] == 1 && b > 0) {
        flag  = 1;
        days ++;
        b --;
        continue;
      }
      if (week[j] == 2 && c > 0) {
        flag  = 1;
        days ++;
        c --;
        continue;
      }
      if (!flag) break;
    }

    d = max(d, days);
  }
  cout << res + d << endl;
  return 0;
}
