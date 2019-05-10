#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;

int n;
int a[MAX_N], b[MAX_N];
int sorted_a[MAX_N], sorted_b[MAX_N];
map<int, int> a_pos, b_pos;
map<int, int> sorted_a_pos, sorted_b_pos;
bool cmp(int a, int b){
  return a > b;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a_pos[a[i]] = i;
    sorted_a[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    b_pos[b[i]] = i;
    sorted_b[i] = b[i];
  }
  sort(sorted_a, sorted_a + n);
  sort(sorted_b, sorted_b + n, cmp);
  for(int i = 0; i < n; i ++) {
    sorted_a_pos[sorted_a[i]] = i;
    sorted_b_pos[sorted_b[i]] = i;
  }
  int res = 0;
  for (int i = 0; i < n; i ++) {
    if (sorted_a_pos[a[i]] != sorted_b_pos[b[i]]) {
      res ++;
      int right_b = sorted_b[sorted_a_pos[a[i]]];
      int right_b_pos = b_pos[right_b];
      int curr_b_pos = b_pos[b[i]];
      b_pos[b[i]] = right_b_pos;
      b_pos[right_b] = curr_b_pos;
      swap(b[i], b[right_b_pos]);
    }
  }
  printf("%d\n", res);
  return 0;
}
