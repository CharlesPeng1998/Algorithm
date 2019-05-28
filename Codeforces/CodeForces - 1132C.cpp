#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;

pair<int,int> section[5005];
int paint_cnt[5005]; //各块被覆盖的次数
int only_one[5005]; //统计只有一次覆盖的块个数
int p[50005];
int n,q;

int op(int idx){
  memset(paint_cnt,0,sizeof(paint_cnt));
  memset(p,0,sizeof(p));
  #if 0  //这个计算方法O(n^2)太慢了
  for(int i=0;i<q;i++){
    if(i==idx) continue;
    for(int j=section[i].first;j<=section[i].second;j++) paint_cnt[j]++;
  }
  #endif

  for(int i=0;i<q;i++){
    if(i==idx) continue;
    p[section[i].first]++;
    p[section[i].second]--;
  }
  int c=0;
  for(int i=0;i<n;i++){
    c+=p[i];
    paint_cnt[i]=c;
  }

  memset(only_one,0,sizeof(only_one));
  only_one[0]=paint_cnt[0]==1?1:0;
  for(int i=0;i<n;i++){
    only_one[i+1]=only_one[i]+(paint_cnt[i]==1?1:0);
  }
  int res=INF;int ans=0;
  for(int i=0;i<q;i++){
    if(i==idx) continue;
    res=min(res,only_one[section[i].second]-only_one[section[i].first]);
  }
  for(int i=0;i<n;i++){
    if(paint_cnt[i]) ans++;
  }
  return ans-res;

}
int main(){
  cin>>n>>q;
  for (int i=0;i<q;i++) {
    cin>>section[i].first>>section[i].second;
    section[i].first--;
  }
  int ans=0;
  for(int i=0;i<q;i++){
    ans=max(ans,op(i));
  }
  cout<<ans<<endl;
  return 0;
}
