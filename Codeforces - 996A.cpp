#include <bits/stdc++.h>

using namespace std;

int n;
int bill[] = {1, 5, 10, 20, 100};
int main() {
  scanf("%d", &n);
  int res = 0;
  for (int i = 4; i >= 0 ; i --) {
    if (n >= bill[i]) {
      res += n / bill[i];
      n = n % bill[i];
    }
  }
  printf("%d\n", res);
  return 0;
}
