#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//Runtime Error


int n,d,t;
int x,y;
//pair<int,int> coordinate[1000];
pair<double,double> range[1500];

int main() {
  t=1;
  while (scanf("%d %d",&n,&d)) {
    int res=0;
    int flag=1;
    if (n==0&&d==0) break;

    for(int i=0;i<n;i++) {
      scanf("%d %d",&x,&y);
      if (y>d) {
        flag=0;
      }
      else {
        range[i].first=x-sqrt(d*d-y*y);
        range[i].second=x+sqrt(d*d-y*y);
      }
    }

    if (!flag) {//存在够不着的小岛
      res=-1;
    }
    else {
      sort(range,range+n);
      double end=range[0].second;
      res++;
      for (int i=1;i<n;i++) {
        if (range[i].first<=end) {
          end=min(range[i].second,end);
        }
        else {
          res++;
          end=range[i].second;
        }
      }
    }
    printf("Case %d: %d\n",t++,res);
  }
  return 0;
}
