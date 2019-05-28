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
#define INF 0x3f3f3f3f
using namespace std;
#define MAX 100000

int N;
int time_pos[100001][11]; //状态time_pos[T][x]表示T时刻在x坐标以后可接到的最大数量

int mymax(int a, int b, int c)
{
    int m=a>b? a:b;
    return m>c? m:c;
}

//矩阵动规
void solve(int m)
{
    int M=0;
    //从矩阵的倒数第二层开始递推
    for (int i=m-1;i>=0;i--)
    {
        //这里要注意不能包括x=0和x=10，这两个坐标不满足以下转移方程，需要特殊处理
        for (int j=1;j<10;j++)
        {
            time_pos[i][j]=time_pos[i][j]+mymax(time_pos[i+1][j-1],time_pos[i+1][j],time_pos[i+1][j+1]);
        }

        //对x=0和x=10进行特殊的状态转移方程处理
        time_pos[i][0]+=max(time_pos[i+1][0],time_pos[i+1][1]);
        time_pos[i][10]+=max(time_pos[i+1][10],time_pos[i+1][9]);
    }

}

int main()
{
    int x,T;
    while (scanf("%d",&N) && N)
    {
        int max=1;
        memset(time_pos,0,sizeof(time_pos));
        for (int i=1;i<=N;i++)
        {
            scanf("%d%d",&x,&T);
            time_pos[T][x]++;

            //max记录最大的时间点，稍后动规将从该时间点开始
            if (T>max)
            {
                max=T;
            }
        }

        solve(max);

        int ans=time_pos[0][5]; //初始点的状态pos_time[0][5]即所求

        printf("%d\n",ans);

    }

    return 0;
}
