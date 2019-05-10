#include <iostream>
#include <algorithm>
#include <queue>
#define MAXC 2505
#define MAXL 2505
using namespace std;

int C,L;
struct Cow{
  int spf_min;
  int spf_max;

  friend bool operator<(Cow a, Cow b){
    return a.spf_max>b.spf_max;
  }
}cow[MAXC];

struct Bottle{
  int spf;
  int cover;
}bottle[MAXL];

bool compare_bottle(Bottle a,Bottle b){
  return a.spf<b.spf;
}

bool compare_cow(Cow a, Cow b){
  return a.spf_min<b.spf_min;
}


int main(){
  cin>>C>>L;
  for(int i=0;i<C;i++) cin>>cow[i].spf_min>>cow[i].spf_max;
  for(int i=0;i<L;i++) cin>>bottle[i].spf>>bottle[i].cover;
  sort(bottle,bottle+L,compare_bottle);
  sort(cow,cow+C,compare_cow);
  priority_queue<Cow> q;
  for(int i=0;i<C;i++) q.push(cow[i]);
  int res=0;
  while(!q.empty()){
    Cow head=q.top();
    q.pop();
    for(int i=0;i<L;i++){
      if(bottle[i].cover>0 && bottle[i].spf>=head.spf_min && bottle[i].spf<=head.spf_max){
        bottle[i].cover--;
        res++;
        break; // 找到一个满足条件的防晒霜则需要break掉，因为一个牛只需要一个防晒霜
      }
    }
  }
  cout<<res<<endl;
  return 0;
}
