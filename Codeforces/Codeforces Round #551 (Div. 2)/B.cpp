#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int n, m, h;
int front[MAX];
int l[MAX];
int top[MAX][MAX];
int main() {
  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) cin >> front[i];
  for (int i = 0; i < n; i++) cin >> l[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> top[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (top[i][j]) {
        top[i][j] = min(front[j], l[i]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << top[i][j] <<' ';
    }
    cout << endl;
  }
  return 0;
}
