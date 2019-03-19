/*贪心策略：
依次取最大质量的进行合并
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int N;
int m[105];
int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>m[i];
  }
  sort(m,m+N);
  float res=m[N-1];
  for(int i=N-2;i>=0;i--){
    res=2*sqrt(res*m[i]);
  }
  printf("%.3f\n",res);
  return 0;
}
