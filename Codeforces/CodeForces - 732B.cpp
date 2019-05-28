#include <bits/stdc++.h>
#define MAX_N 505

using namespace std;

int n, k;
int a[MAX_N];
int b[MAX_N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  int addition = 0;
  for (int i = 0; i < n - 1; i++) {
    if (b[i] + b[i + 1] < k) {
      addition += k - (b[i] + b[i + 1]);
      b[i + 1] += k - (b[i] + b[i + 1]);
    }
  }
  printf("%d\n", addition);
  for (int i = 0; i < n; i ++) printf("%d ", b[i]);
  printf("\n");
  return 0;
}
