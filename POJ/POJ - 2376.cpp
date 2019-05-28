#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define MAXN 25000
using namespace std;

int N,T;
int min_cow_num;
pair<int,int> cows[MAXN];
int visited[MAXN];

bool compare(pair<int,int> p1, pair<int,int>p2) {
  return p1.first>p2.first;
}

int main() {
  while (scanf("%d %d",&N,&T)!=EOF) {
    memset(visited,0,sizeof(visited));
    min_cow_num=0;
     for (int i=0;i<N;i++) {
       scanf("%d %d",&cows[i].second,&cows[i].first); //second是开始时间，first是结束时间
     }
     sort(cows,cows+N,compare); //按照结束时间从大到小排序
     int h=0,t=0; //上一段的开始时间h与结束时间t
     while (t<T) {
       bool flag=0;
       for (int i=0;i<N;i++) {
         if (cows[i].second<=t+1&&cows[i].second>h&&cows[i].first>t&&!visited[i]) {
           /*贪心策略：对于每次选择的区间
           开始时间<=上个区间结束时间+1（不是<=t，而是可以从t+1开始）
           开始时间>上个区间开始时间
           结束时间>上次区间结束时间
           */
           visited[i]=1;
           min_cow_num++;
           t=cows[i].first;
           h=cows[i].second;
           flag=1;
           break;
         }
       }
       if (!flag) {
         min_cow_num=-1;
         break;
       }
     }
     printf("%d\n",min_cow_num);
  }
  return 0;
}
