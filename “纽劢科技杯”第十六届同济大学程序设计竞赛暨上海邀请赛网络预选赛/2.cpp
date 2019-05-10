#include <bits/stdc++.h>

using namespace std;

int N;
int main() {
  cin >> N;
  int res = 0;
  if (N <= 10) {
    if (N >= 5) res = 10 - N;
    else res = 1 + N;
  }
  else {
    int r = N - 10;
    if (r < 10) {
      res = min(r, 10 - r);
    }
    else if (r >= 10 && r <= 99) {
      int nxt = r % 10;
      if (nxt > 5) {
        res += r / 10 + 1;
        res += 10 - nxt;
      }
      else {
        res += r / 10;
        res +=nxt;
      }
    }
    else if (r >= 100) {
      int nxt = r / 10 % 10;
      if (nxt > 5) {
        res += r / 100 + 1;
        r = (res * 100 > 999?999:res * 100) - r;
        nxt = r % 10;
        if (nxt > 5) {
          res += r / 10 + 1;
          res += 10 - nxt;
        }
        else {
          res += r / 10;
          res +=nxt;
        }
      }
      else {
        res += r / 100;
        r = r - res * 100;
        nxt = r % 10;
        if (nxt > 5) {
          res += r / 10 + 1;
          res += 10 - nxt;
        }
        else {
          res += r / 10;
          res +=nxt;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
