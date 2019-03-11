#include <iostream>
#include <algorithm>

using namespace std;
int num[10];
int temp[11][10];
int sum;
int N;
int main() {
  cin>>N>>sum;
  for (int i=0;i<N;i++) {
    num[i]=i+1;
  }
  do {
    for (int i=0;i<N;i++) {
      temp[0][i]=num[i];
    }
    int depth=1;
    int n=N;
    while (depth!=N) {
      for (int i=0;i<n-1;i++) {
        temp[depth][i]=temp[depth-1][i]+temp[depth-1][i+1];
      }
      depth++;
      n--;
    }
    if (temp[depth-1][0]==sum) {
      for (int i=0;i<N;i++) {
        cout<<num[i]<<' ';
      }
      cout<<endl; return 0;
    }
  }while (next_permutation(num,num+N));
  return 0;
}
