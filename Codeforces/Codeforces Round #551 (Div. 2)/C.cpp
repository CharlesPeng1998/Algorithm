#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

int n;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cin >> s;
  int a, b;
  int val = 0;
  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') val++;
    else if (s[i] == ')') val--;
    else cnt++;
  }
  val = 0 - val;
  a = (cnt + val) / 2;
  b = (cnt - val) / 2;
  int flag = 1;
  val = 0;
  #if DEBUG
  cout << "a = " << a << " b = " << b << endl;
  #endif
  for (int i = 0; i < s.length(); i++) {
    if (val < 0) {
      flag = 0;
      break;
    }
    if (s[i] == '(') val++;
    else if (s[i] == ')') val--;
    else if (s[i] == '?') {
      if (a) {
        s[i] = '(';
        a--;
        val++;
      }
      else {
        s[i] = ')';
        b--;
        val--;
      }
    }
    if (i != s.length() - 1 && val == 0) flag = 0;
    if (i == s.length() - 1 && val != 0) flag = 0;
  }
  if (flag) cout << s << endl;
  else cout << ":(" << endl;
  return 0;
}
