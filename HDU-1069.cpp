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

int N;
int n;
struct Block
{
    int x;
    int y;
    int h;
};

Block block[91];
int dp[91]; //dp[i]表示从结点[i]出发可达到的最大高度
bool G[91][91]; //邻接矩阵

int solve(int pos)
{
    int& ans=dp[pos];
    if (ans>0)
        return ans ;

    ans=block[pos].h;
    for (int j=1;j<=n;j++)
    {
        if (G[pos][j])
        {
            ans=max(ans,solve(j)+block[pos].h);
        }
    }

    return ans;
}

int main()
{
    int count=1;
    int a,b,c;
    while (scanf("%d",&N) && N)
    {
        for (int i=1;i<=N;i++)
        {
            scanf("%d%d%d",&a,&b,&c);

            //将N个方块转化为3*N个高度固定的方块
            block[3*i].x=a;
            block[3*i].y=b;
            block[3*i].h=c;

            block[3*i-1].x=a;
            block[3*i-1].y=c;
            block[3*i-1].h=b;

            block[3*i-2].x=b;
            block[3*i-2].y=c;
            block[3*i-2].h=a;
        }
        n=N*3; //高度固定的方块数量

        memset(dp,0,sizeof(dp));
        memset(G,0,sizeof(G));
        //确定邻接关系
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if ((block[i].x<block[j].x && block[i].y<block[j].y) || (block[i].x<block[j].y && block[i].y<block[j].x))
                {
                    G[i][j]=1;
                }
            }
        }

        for (int i=1;i<=n;i++)
        {
            solve(i);
        }

        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (dp[i]>ans)
            {
                ans=dp[i];
            }
        }

        printf("Case %d: maximum height = %d\n",count,ans);
        count++;
    }

    return 0;
}
