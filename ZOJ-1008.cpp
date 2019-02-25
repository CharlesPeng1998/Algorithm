#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int size;
int square[26][4];
int mark[26];


//used:当前已经使用的方块数量.sqaure_no:当前用来进行搜索的方块编号
//row,col:用来进行搜索的方块放置的坐标
bool DFS(int square_no,int row,int col)
{
    bool over;
    //若方块全部使用，则说明游戏可完成
    for (int i=1;i<=size*size;i++)
    {
        if (mark[i]==0)
        {
            over=0;
        }
    }
    if (over)
    {
        return true;
    }

    //为方块寻找上边匹配的
    if (row!=0)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][2]==square[square_no][0] && mark[i]!=1)
            {
                mark[i]=1;
                //对匹配的方块继续做递归搜索操作
                if (DFS(i,row-1,col))
                {
                    return 1;
                }
                else mark[i]=0; //这个到底有没有必要？
            }
        }
    }

    //寻找右边匹配的
    if (col!=size-1)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][3]==square[square_no][1] && mark[i]!=1)
            {
                mark[i]=1;
                //对匹配的方块继续做递归搜索操作
                if (DFS(i,row,col+1))
                {
                    return 1;
                }
                else mark[i]=0;
            }
        }
    }

    //寻找下边匹配
    if (row!=size-1)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][0]==square[square_no][2] && mark[i]!=1)
            {
                mark[i]=1;
                //对匹配的方块继续做递归搜索操作
                if (DFS(i,row+1,col))
                {
                    return 1;
                }
                else mark[i]=0;
            }
        }
    }

    //寻找左边匹配
    if (col!=0)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][1]==square[square_no][3] && mark[i]!=1)
            {
                mark[i]=1;
                //对匹配的方块继续做递归搜索操作
                if (DFS(i,row,col-1))
                {
                    return 1;
                }
                else mark[i]=0;
            }
        }
    }

    return 0;
}

int main()
{
    int count=1;

    while (1)
    {
        scanf("%d",&size);
        if (size==0)
            break;

        for (int i=1;i<=size*size;i++)
        {
            scanf("%d %d %d %d",&square[i][0],&square[i][1],&square[i][2],&square[i][3]);
        }

        bool flag=0;

        memset(mark,0,sizeof(mark));
        mark[1]=1;
        for (int j=0;j<size;j++)
        {
            for (int k=0;k<size;k++)
            {
                if (DFS(1,j,k))
                {
                    flag=1;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        mark[1]=0;

        if (flag)
            cout<<"Game "<<(count++)<<": Possible"<<endl<<endl;
        else cout<<"Game "<<(count++)<<": Impossible"<<endl<<endl;
    }
    return 0;
}
