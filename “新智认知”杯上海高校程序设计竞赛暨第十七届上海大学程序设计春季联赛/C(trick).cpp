/*
注意到字符串的字符是等概率随机产生，
我们可以假设当我们选取的密码大于某一长度时，
将不会出现重复密码。

当然这是一种很trick的做法
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m;
set<string> my_set;
string str, psw;
int main() {
  scanf("%d%d", &n, &m);
  cin >> str;
  ll res = 0;
  for (int i = m; i <= min(8, n); i++) {
      for (int j = 0; j <= n - i; j++) {
        psw = str.substr(j, i);
        my_set.insert(psw);
      }
  }
  res += my_set.size();
  for (int i = max(9, m); i <= n; i++) {
    res += n - i + 1;
  }
  cout << res << endl;
  return 0;
}
