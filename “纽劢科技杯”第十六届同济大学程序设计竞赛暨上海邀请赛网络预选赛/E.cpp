#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;

int n , k;
map<int ,int> my_map;
int p[MAX_N];
int pij;

bool compare(int a, int b) {
  return a > b;
}
int used[MAX_N];
int main() {
  cin >> n >> k;
  int idx = 0;
  memset(used, 0, sizeof used);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &pij);
      my_map[pij] = i;
      p[idx++] = pij;
    }
  }
  sort(p, p + idx, compare);
  int w = 0;
  int Max = p[0];
  int Min;
  for (int i = 0; i < idx; i++) {
    int id = my_map[p[i]];
    if(!used[id]){
      w++;
      Min = p[i];
      used[id] = 1;
    }
    if (w >= n) break;
  }
  cout << Max - Min <<endl;
  return 0;
}
