#include <bits/stdc++.h>
#define MAX_D 1000005
#define DEBUG 0
using namespace std;
typedef long long ll;
int n, t;
int d[11];
ll A[MAX_D];
ll B[MAX_D];
map<ll, int> my_map;
int main() {
  scanf("%d", &n);
  int total = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", d + i);
    total *= d[i];
  }
  for (int i = 0; i < total; i++) {
    ll id = 0;
    int a;
    for (int j = 0; j < n; j++) {
      scanf("%d", &a);
      id = id * 10 + a;
    }
    A[i] = id;
    my_map[A[i]] = i;
    id = 0;
    for (int j = 0; j < n; j++) {
      scanf("%d", &a);
      id = id * 10 + a;
    }
    B[i] = id;
  }
  scanf("%d", &t);
  int res = 0;
  for (int i = 0; i < total; i++) {
    if (A[i] == B[i]) continue;
    res++;
    int pos = my_map[B[i]];
    my_map[B[i]] = i;
    my_map[A[i]] = pos;
    swap(A[i], A[pos]);
  }
  if (res <= t && (t - res) % 2 == 0) printf("YES\n");
  else printf("NO\n");
  return 0;
}
