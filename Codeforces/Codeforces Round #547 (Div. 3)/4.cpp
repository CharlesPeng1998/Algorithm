#include <bits/stdc++.h>
using namespace std;

string l, r;
int n;
int main() {
  vector<vector<int>> left(26); // vector 别作为全局变量
  vector<vector<int>> right(26);
  vector<int> ques_mark_left;
  vector<int> ques_mark_right;
  vector<pair<int, int>> res;
  cin >> n;
  cin >> l;
  cin >> r;
  for (int i = 0; i < int(l.length()); i++) {
    if (l[i] == '?') ques_mark_left.push_back(i+1);
    else left[l[i] - 'a'].push_back(i+1);
  }
  for (int i = 0; i < int(r.length()); i++) {
    if (r[i] == '?') ques_mark_right.push_back(i+1);
    else right[r[i] - 'a'].push_back(i+1);
  }
  vector<int> curr_left(26), curr_right(26);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < min(int(left[i].size()), int(right[i].size())); j++) {
      res.push_back(make_pair(left[i][j], right[i][j]));
      curr_left[i] = curr_right[i] = min(int(left[i].size()), int(right[i].size())); //下次记录当前位置
    }
  }
  for (int i = 0; i < 26; i++) {
    while (curr_left[i] < int(left[i].size()) && !ques_mark_right.empty()) {
      res.push_back(make_pair(left[i][curr_left[i]], ques_mark_right[ques_mark_right.size() - 1]));
      curr_left[i]++;
      ques_mark_right.pop_back();
    }
  }
  for (int i = 0; i < 26; i++) {
    while (curr_right[i] < int(right[i].size()) && !ques_mark_left.empty()) {
      res.push_back(make_pair(ques_mark_left[ques_mark_left.size() - 1], right[i][curr_right[i]]));
      curr_right[i]++;
      ques_mark_left.pop_back();
    }
  }
  for (int i = 0; i < min(int(ques_mark_left.size()), int(ques_mark_right.size())); i++) {
    res.push_back(make_pair(ques_mark_left[i], ques_mark_right[i]));
  }
  printf("%d\n", res.size());
  for (int i = 0; i < int(res.size()); i++) {
    printf("%d %d\n", res[i].first, res[i].second);
  }
  return 0;
}
