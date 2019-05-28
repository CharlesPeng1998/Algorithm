/*贪心+优先队列
贪心策略：
1.设置一个优先队列，其中结束时间早的优先级高
2.先将全部区间根据开始时间从小到大排序
3.第一个区间入队列
4.依次取剩余区间，将开始时间与队列头的结束时间比较：
  (1)早：增加一个牛棚，该区间入队
  (2)晚：放入队列头所属的牛棚，队列头出队且该区间入队
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

struct Cow{
  int begin;
  int end;
  int id;

  friend bool operator<(Cow a,Cow b) {
    return a.end>b.end;
  }
}cows[50000];
int stall[50000];

bool compare(Cow c1,Cow c2){
  return c1.begin<c2.begin;
}

int main(){
  int N;
  int stall_id=1;
  scanf("%d",&N);
  for (int i=0;i<N;i++){
    scanf("%d %d",&cows[i].begin,&cows[i].end);
    cows[i].id=i;
  }
  sort(cows,cows+N,compare);
  priority_queue<Cow> q;
  q.push(cows[0]);
  stall[cows[0].id]=stall_id;
  for(int i=1;i<N;i++){
    Cow top=q.top();
    if(cows[i].begin>top.end) {
      stall[cows[i].id]=stall[top.id];
      q.pop();
      q.push(cows[i]);
    }
    else{
      stall[cows[i].id]=++stall_id;
      q.push(cows[i]);
    }
  }

  printf("%d\n",stall_id);
  for(int i=0;i<N;i++) {
    printf("%d\n",stall[i]);
  }
  return 0;
}
