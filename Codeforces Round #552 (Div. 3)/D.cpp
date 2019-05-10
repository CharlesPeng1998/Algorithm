#include <bits/stdc++.h>
#define MAX_N 200005
using namespace std;

int n, b, a;
int s[MAX_N];
int main() {
  cin >> n >> b >> a;
  int curr_b = b;
  int curr_a = a;
  for (int i = 0; i < n; i++) cin >> s[i];
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (curr_b == 0 && curr_a == 0) break;
    if (s[i] == 1) {
      if (curr_a < a && curr_b > 0) {
        curr_a++; curr_b--;
        res ++;
      }
      else {
        curr_a--; res++;
      }
    }
    else {
      if (curr_a > 0) {
        curr_a--; res++;
      }
      else{
        curr_b--; res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
