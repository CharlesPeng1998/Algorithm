//这道题有必要写入博客
//此为AC代码
//这道题困扰了一些时间，需要回味
#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
#define judge(i,j) i>0&&i<=h&&j>0&&j<=w&&board[i][j]!=1
using namespace std;

int board[21][21];
int w,h;
int si,sj,gi,gj;
int res,steps;
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};

void dfs(int i,int j) {
  if (steps>10) return;
   //判断当前位置周围是否存在可移动方向的标志
  for (int k=0;k<4;k++) {
    int ok=0;
    int pi=i+di[k]; int pj=j+dj[k];
    while (judge(pi,pj)) {
      ok=1; //周围存在可移动方向
      if (board[pi][pj]==3) {
        if (steps<res) res=steps;
      }
      pi+=di[k]; pj+=dj[k];
    }
    if (board[pi][pj]==1&&ok) {
      board[pi][pj]=0;
      steps++;
      dfs(pi-di[k],pj-dj[k]);
      steps--;
      board[pi][pj]=1; //注意回溯到原状态
    }
  }
}

int main() {
  while (cin>>w>>h) {
    if (w==0 && h==0) break;
    res=INF; steps=1;
    memset(board,0,sizeof(board)); //不对数组初始化必定WA，什么原理？
    /*
    如果不对二维数组进行初始化操作，在指定区域外可能存在上次数据留下的
    “1”，导致程序第29行的错误判断
    */
    for (int i=1;i<=h;i++) {
      for (int j=1;j<=w;j++) {
        cin>>board[i][j];
        if (board[i][j]==2) {si=i;sj=j;}
        if (board[i][j]==3) {gi=i;gj=j;}
      }
    }

    dfs(si,sj);
    if (res>10) cout<<-1<<endl;
    else cout<<res<<endl;
  }

  return 0;
}
