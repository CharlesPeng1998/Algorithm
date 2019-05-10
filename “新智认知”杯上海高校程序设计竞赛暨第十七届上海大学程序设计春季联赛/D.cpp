#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> my_stack;
int last_pos[200];
bool used[200];
int main() {
  cin >> s;
  memset(last_pos, -1, sizeof last_pos);
  memset(used, 0, sizeof used);
  for (int i = 0; i < s.length(); i++) {
    last_pos[s[i]] = max(last_pos[s[i]], i);
  }
  for (int i = 0; i < s.length(); i++) {
    if (used[s[i]]) continue;
    while (!my_stack.empty() && last_pos[my_stack.top()] > i && my_stack.top() > s[i]) {
      used[my_stack.top()] = 0;
      my_stack.pop();
    }
    my_stack.push(s[i]);
    used[s[i]] = 1;
  }
  string ans;
  while (!my_stack.empty()) {
    ans += my_stack.top();
    my_stack.pop();
  }
  for (int i = ans.length() - 1; i >= 0; i--) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
