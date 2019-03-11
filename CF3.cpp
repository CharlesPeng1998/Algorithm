#include <bits/stdc++.h>
#define MAXN 200004
using namespace std;

int n;
int a[MAXN];
int p[MAXN];
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  sort(a,a+n);
  int res=0;
  p[1]=a[1]-a[0];
  for(int i=2;i<n;i++) {
    p[i]=p[i-1]+a[i]-a[i-1];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(p[j]-p[i]<=5) {
        int len=j-i+1;
        res=max(res,len);
      }
    }
  }
  printf("%d\n",(res==0?1:res));
  return 0;
}
