#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

const int maxn = 100005;
int a[2 * maxn];
int ans[2 * maxn];
int n;

int main() {
  cin >> n;
  int flag = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 1) flag = 1;
    a[i + n] = a[i];
  }
  if (!flag) {
    if (n & 1) {
      for (int i = 0; i < n; i++) cout << "First" << endl;
    }
    else {
      for (int i = 0; i < n; i++) cout << "Second" << endl;
    }
    return 0;
  }
  int j;
  for (j = 2 * n - 1; j >= 0; j --) {
    if (a[j] > 1) {ans[j] = 1; break;}
  }
  for (int i = j - 1; i >= 0; i --) {
    if (a[i] == 1) ans[i] = -ans[i + 1];
    else ans[i] = 1;
  }

  for (int i = 0; i < n; i ++) {
    if (ans[i] == 1) cout << "First" << endl;
    else cout << "Second" << endl;
  }
  return 0;
}
