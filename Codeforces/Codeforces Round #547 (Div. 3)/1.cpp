#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
  cin >> n >> m;
  if (m % n != 0) cout << -1 << endl;
  else {
    int mul = m / n;
    int step = 0;
    while (mul != 1) {
      if (mul % 2 == 0) {
        mul /= 2;
        step++;
      }
      else if (mul % 3 == 0) {
        mul /= 3;
        step++;
      }
      else {
        cout << -1 <<endl;
        return 0;
      }
    }
    cout << step << endl;
  }
  return 0;
}
