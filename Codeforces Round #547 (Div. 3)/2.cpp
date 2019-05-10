#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n;
int schedule[2 * MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &schedule[i]);
    schedule[i + n] = schedule[i];
  }
  int res = 0;
  int curr = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (schedule[i] == 1) curr++;
    else {
      res = max(res, curr);
      curr = 0;
    }
  }
  cout << res << endl;
  return 0;
}
