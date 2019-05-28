#include <bits/stdc++.h>
#define MAX_N 105
using namespace std;

int n, t;
struct route{
  int time;
  int id;
};
route r[MAX_N];
bool compare(route a, route b) {
  return a.time < b.time;
}
int main() {
  cin >> n >> t;
  int s, d;
  for (int i = 0; i < n; i++) {
    cin >> s >> d;
    while (s < t) s += d;
    r[i].time = s;
    r[i].id = i + 1;
  }
  sort(r, r + n, compare);
  cout << r[0].id << endl;
  return 0;
}
