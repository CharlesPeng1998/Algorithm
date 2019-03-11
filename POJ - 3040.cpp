#include <iostream>
#include <algorithm>
using namespace std;

int N,C;
pair<int,int> coin[25];

bool pay(){
  int rest=C;
  for(int i=0;i<N;i++){
    if(coin[i].second<=0) continue;
    int num=rest/coin[i].first;
    if(num<=coin[i].second){
      coin[i].second-=num;
      rest-=num*coin[i].first;
    }
    else{
      rest-=coin[i].second*coin[i].first;
      coin[i].second=0;
    }
    if(rest<=0) return true;
  }

  for(int i=N-1;i>=0;i--){
    if(coin[i].second<=0) continue;
    int num;
    if(rest%coin[i].first) num=rest/coin[i].first+1;
    else num=rest/coin[i].first;
    if(num<=coin[i].second){
      coin[i].second-=num;
      rest-=num*coin[i].first;
    }
    else{
      rest-=coin[i].second*coin[i].first;
      coin[i].second=0;
    }
    if(rest<=0) return true;
  }
  return false;
}

bool compare(pair<int,int>a,pair<int,int>b){
  return a.first>b.first;
}

int main(){
  cin>>N>>C;
  for(int i=0;i<N;i++) cin>>coin[i].first>>coin[i].second;
  int res=0;
  sort(coin,coin+N,compare);
  while(pay()) res++;
  cout<<res<<endl;
  return 0;
}
