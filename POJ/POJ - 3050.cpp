/*
基础DFS练习
可以走回头路
递归终止条件为步数
*/
#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;

char board[6][6];
map<string,int> my_map;
int res;
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

void dfs(int i,int j,int step,string seq) {
  if (step==5) {
    if (!my_map.count(seq)) {
      my_map[seq]=1;
      res++;
    }
    return;
    /*脑子出问题了
    这个return放在上面那个if语句里面，导致递归不能及时终止
    */
  }

  for (int k=0;k<4;k++) {
    int ci=i+di[k]; int cj=j+dj[k];
    if(ci>=0 && ci<5 && cj>=0 && cj<5) dfs(ci,cj,step+1,seq+board[ci][cj]);
  }
}

int main() {
  string seq;
  for (int i=0;i<5;i++) {
    for (int j=0;j<5;j++) {
      cin>>board[i][j];
    }
  }
  res=0;
  for (int i=0;i<5;i++) {
    for (int j=0;j<5;j++) {
      seq.clear();
      dfs(i,j,0,seq+board[i][j]);
    }
  }
  cout<<res<<endl;
  return 0;
}
