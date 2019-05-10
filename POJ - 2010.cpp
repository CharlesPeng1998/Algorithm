#include <iostream>
#include <algorithm>
#include <queue>
#define MAXC 100005
#define INF 0x3f3f3f3f
#define score first
#define aid second
using namespace std;

int N,C,F;
pair<int,int> apply[MAXC];
int lower[MAXC];
int upper[MAXC];

int main(){
  cin>>N>>C>>F;
  for(int i=0;i<C;i++) cin>>apply[i].score>>apply[i].aid;
  sort(apply,apply+C);
  int half=N/2;
  int total=0;
  priority_queue<int> q1;
  for(int i=0;i<C;i++){
    lower[i]=int(q1.size())==half?total:INF;
    total+=apply[i].aid;
    q1.push(apply[i].aid);
    if(int(q1.size())>half){
      total-=q1.top();
      q1.pop();
    }
  }
  total=0;
  priority_queue<int> q2;
  for(int i=C-1;i>=0;i--){
    upper[i]=int(q2.size())==half?total:INF;
    total+=apply[i].aid;
    q2.push(apply[i].aid);
    if(int(q2.size())>half){
      total-=q2.top();
      q2.pop();
    }
  }
  int flag=0;
  int res=0;
  for(int i=C-1;i>=0;i--){
    if(lower[i]+apply[i].aid+upper[i]<=F){
      flag=1;
      res=apply[i].score;
      break;
    }
  }
  if(flag) cout<<res<<endl;
  else cout<<-1<<endl;
  return 0;
}
