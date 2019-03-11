#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int cost[300000];
int coupon[300000];

bool compare(int a,int b) {
  return a>b;
}

int main() {
  long long total=0;
  scanf("%d",&n);
  for (int i=0;i<n;i++) {
    scanf("%d",&cost[i]);
    total+=cost[i];
  }
  scanf("%d",&m);
  for (int i=0;i<m;i++) {
    scanf("%d",&coupon[i]);
  }
  sort(cost,cost+n,compare);
  for (int i=0;i<m;i++) {
    long long res=total-cost[coupon[i]-1];
    printf("%lld\n",res);
  }
  return 0;
}
