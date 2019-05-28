#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n;
int q[MAXN];
int per[MAXN];
int mark[MAXN];
int prefix[MAXN];
int main() {
  cin >> n;
  prefix[1] = 0;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d", &q[i]);
    prefix[i + 1] = prefix[i] + q[i];
  }
  memset(mark, 0, sizeof mark);
  int min_val = 0;
  for(int i = 2; i <= n; i++){
    if (prefix[i] < min_val) min_val = prefix[i];
  }
  int first_elem = 1 - min_val;
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    int val = first_elem + prefix[i];
    if (!mark[val] && val >= 1 && val <= n) {
      per[i] = val;
      mark[val] = 1;
    }
    else {
      flag = 0;
      break;
    }
  }
  if (flag) {
    for (int i = 1; i <= n; i++) printf("%d ", per[i]);
    printf("\n");
  }
  else printf("-1\n");
  return 0;
}
