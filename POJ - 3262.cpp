/*贪心策略：每次选择T/D最小的一个牛
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 100005
using namespace std;

int N;
pair<int,int> cow_info[MAXN];
bool compare(pair<int,int> a,pair<int,int> b){
  return (float(a.first)/a.second)<(float(b.first)/b.second);
}
int main(){
  scanf("%d",&N);
  long long res=0;
  long long total_consum=0;
  for(int i=0;i<N;i++){
    scanf("%d%d",&cow_info[i].first,&cow_info[i].second);
    total_consum+=cow_info[i].second;
  }
  sort(cow_info,cow_info+N,compare);
  for(int i=0;i<N;i++){
    total_consum-=cow_info[i].second;
    res+=total_consum*cow_info[i].first*2;
  }
  printf("%lld\n",res);
  return 0;
}
