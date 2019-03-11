/*
只有十行
对行进行DFS，2^10的复杂度
对于每个状态，逐列检查，将0多于1的列进行翻转
*/

#include <iostream>

using namespace std;
int board[11][10001];
int r,c;
int res,count;

void row_op(int row) { //将一行翻转
  for (int i=1;i<=c;i++) {
    if (board[row][i]==1) {
      board[row][i]=0; count--;
    }
    else {
      board[row][i]=1;count++;
    }
  }
}

void count_col(int count) { //在当前状态下通过检查每列确定可达到的最大1的数量
  for (int i=1;i<=c;i++) {
    int col_0_num=0;
    for (int j=1;j<=r;j++) {
      if (board[j][i]==0) col_0_num++;
    }
    if (col_0_num>r/2) { //0多于1时进行翻转
      count=count+col_0_num-(r-col_0_num); //翻转后1的总数
    }
  }
  if (count>res) res=count;
}

void dfs(int row) {
  row_op(row);
  count_col(count);
  for (int i=row+1;i<=r;i++) {
    dfs(i);
  }
  row_op(row);
}

int main() {
  while (cin>>r>>c) {
    if (r==0 && c==0) break;
    res=count=0;

    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) {
        cin>>board[i][j];
        if (board[i][j]==1) count++; //确定初始有多少个1
      }
    }

    //对初始状态检查
    count_col(count);

    //对行进行dfs搜索
    for (int i=1;i<=r;i++) {
      dfs(i);
    }
    cout<<res<<endl;
  }
  return 0;
}
