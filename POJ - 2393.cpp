/*可以O(n^2)解决的 为什么要弄成O(n^2logn)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N,S;
pair<int,int> C_and_Y[10000];
int cost[10000];
int main(){
  scanf("%d%d",&N,&S);
  for (int i=0;i<N;i++) {
    scanf("%d%d",&C_and_Y[i].first,&C_and_Y[i].second);
  }
  long long total=0;
  for(int i=0;i<N;i++) {
    int min=C_and_Y[0].first+(i)*S;
    for(int j=0;j<=i;j++){
      if (C_and_Y[j].first+(i-j)*S<min) min=C_and_Y[j].first+(i-j)*S;
    }
    total+=min*C_and_Y[i].second;
  }
  cout<<total<<endl;
  return 0;
}
