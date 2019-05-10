#include <queue>
#include <iostream>
#include <algorithm>
#define MAXN 10005
#define dis first //到终点的距离
#define fuel second
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b) {
  return a.dis > b.dis;
}

pair<int,int> stop[MAXN];
int K,P;
int N;
int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>stop[i].dis>>stop[i].fuel;
  }
  sort(stop,stop+N,compare);
  cin>>K>>P;
  int stop_idx=0;
  int curr_dis=K;
  bool flag=1;
  int res=0;
  priority_queue<int> q;
  while(curr_dis>0){
    if(P>0){
      curr_dis-=P;
      P=0;
    }
    else{
      for(stop_idx=stop_idx;stop_idx<N;stop_idx++){
        if(stop[stop_idx].dis>=curr_dis) {
          q.push(stop[stop_idx].fuel);
        }
        else break;
      }
      if(q.empty()){
        flag=0;
        break;
      }
      P+=q.top(); q.pop();res++;
    }
  }
  if(flag) cout<<res<<endl;
  else cout<<-1<<endl;
  return 0;
}
