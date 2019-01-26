//这道题有必要写入博客
#include <iostream>
#include <string.h>
using namespace std;

int w,h;
int board[21][21];
int visited[21][21];
int res;

int dfs_up(int i,int j,int n);
int dfs_down(int i,int j,int n);
int dfs_left(int i,int j,int n);
int dfs_right(int i,int j,int n);

int dfs_up(int i,int j,int n) {
  if (i<=0 || i>h || j<=0 || j>w) return 0; //出界
  if (board[i][j]==1) { //撞墙
    board[i][j]=0;
    return -1;
  }
  if (board[i][j]==3) {
    if (n<res || res==0) res=n;
    return 1; //到达终点
  }
  //继续向上移动
  int stat=dfs_up(i-1,j,n);
  if (stat==1) return 1;
  if (stat==0) return 0;
  if (stat==-1) {
    if (i-1>0 && board[i-1][j]!=1) {
      if (dfs_up(i-1,j,n+1)) {
        board[i-1][j]=1;
        return 1;
      }
    }
    if (i+1<=h && board[i+1][j]!=1) {
      if (dfs_down(i+1,j,n+1)) {
        board[i-1][j]=1;
        return 1;
      }
    }
    if (j-1>0 && board[i][j-1]!=1) {
      if (dfs_left(i,j-1,n+1)) {
        board[i-1][j]=1;
        return 1;
      }
    }
    if (j+1<=w && board[i][j+1]!=1) {
      if (dfs_right(i,j+1,n+1)) {
        board[i-1][j]=1;
        return 1;
      }
    }
  }

  return 0;
}
int dfs_down(int i,int j,int n) {
  if (i<=0 || i>h || j<=0 || j>w) return 0; //出界
  if (board[i][j]==1) { //撞墙
    board[i][j]=0;
    return -1;
  }
  if (board[i][j]==3) {
    if (n<res || res==0) res=n;
    return 1; //到达终点
  }
  //继续向上移动
  int stat=dfs_down(i+1,j,n);
  if (stat==1) return 1;
  if (stat==0) return 0;
  if (stat==-1) {
    if (i-1>0 && board[i-1][j]!=1) {
      if (dfs_up(i-1,j,n+1)) {
        board[i+1][j]=1;
        return 1;
      }
    }
    if (i+1<=h && board[i+1][j]!=1) {
      if (dfs_down(i+1,j,n+1)) {
        board[i+1][j]=1;
        return 1;
      }
    }
    if (j-1>0 && board[i][j-1]!=1) {
      if (dfs_left(i,j-1,n+1)) {
        board[i+1][j]=1;
        return 1;
      }
    }
    if (j+1<=w && board[i][j+1]!=1) {
      if (dfs_right(i,j+1,n+1)) {
        board[i+1][j]=1;
        return 1;
      }
    }
  }

  return 0;
}
int dfs_left(int i,int j,int n) {
  if (i<=0 || i>h || j<=0 || j>w) return 0; //出界
  if (board[i][j]==1) { //撞墙
    board[i][j]=0;
    return -1;
  }
  if (board[i][j]==3) {
    if (n<res || res==0) res=n;
    return 1; //到达终点
  }
  //继续向上移动
  int stat=dfs_left(i,j-1,n);
  if (stat==1) return 1;
  if (stat==0) return 0;
  if (stat==-1) {
    if (i-1>0 && board[i-1][j]!=1) {
      if (dfs_up(i-1,j,n+1)) {
        board[i][j-1]=1;
        return 1;
      }
    }
    if (i+1<=h && board[i+1][j]!=1) {
      if (dfs_down(i+1,j,n+1)) {
        board[i][j-1]=1;
        return 1;
      }
    }
    if (j-1>0 && board[i][j-1]!=1) {
      if (dfs_left(i,j-1,n+1)) {
        board[i][j-1]=1;
        return 1;
      }
    }
    if (j+1<=w && board[i][j+1]!=1) {
      if (dfs_right(i,j+1,n+1)) {
        board[i][j-1]=1;
        return 1;
      }
    }
  }

  return 0;
}
int dfs_right(int i,int j,int n) {
  if (i<=0 || i>h || j<=0 || j>w) return 0; //出界
  if (board[i][j]==1) { //撞墙
    board[i][j]=0;
    return -1;
  }
  if (board[i][j]==3) {
    if (n<res || res==0) res=n;
    return 1; //到达终点
  }
  //继续向上移动
  int stat=dfs_right(i,j+1,n);
  if (stat==1) return 1;
  if (stat==0) return 0;
  if (stat==-1) {
    if (i-1>0 && board[i-1][j]!=1) {
      if (dfs_up(i-1,j,n+1)) {
        board[i][j+1]=1;
        return 1;
      }
    }
    if (i+1<=h && board[i+1][j]!=1) {
      if (dfs_down(i+1,j,n+1)) {
        board[i][j+1]=1;
        return 1;
      }
    }
    if (j-1>0 && board[i][j-1]!=1) {
      if (dfs_left(i,j-1,n+1)) {
        board[i][j+1]=1;
        return 1;
      }
    }
    if (j+1<=w && board[i][j+1]!=1) {
      if (dfs_right(i,j+1,n+1)) {
        board[i][j+1]=1;
        return 1;
      }
    }
  }

  return 0;
}
int main() {
  while (cin>>w>>h) {
    res=0;
    if (w==0 && h==0) break;
    for (int i=1;i<=h;i++) {
      for (int j=1;j<=w;j++) {
        cin>>board[i][j];
      }
    }

    for (int i=1;i<=h;i++) {
      for (int j=1;j<=w;j++) {
        if (board[i][j]==2) {
          if (i-1>0 && board[i-1][j]!=1) dfs_up(i-1,j,1);
          if (i+1<=h && board[i+1][j]!=1) dfs_down(i+1,j,1);
          if (j-1>0 && board[i][j-1]!=1) dfs_left(i,j-1,1);
          if (j+1<=w && board[i][j+1]!=1) dfs_right(i,j+1,1);
          break;
          }
        }
      }

      if (res!=0 && res<=10) cout<<res<<endl;
      else cout<<-1<<endl;
  }
  return 0;
}


/*
出错数据
10 10
1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 0 1 1
2 1 0 1 1 1 1 1 1 1
1 1 1 1 1 1 0 1 1 1
1 0 1 0 1 1 1 1 1 1
1 1 1 1 1 3 1 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 0 1
1 0 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

expected:9
mine:-1
*/
