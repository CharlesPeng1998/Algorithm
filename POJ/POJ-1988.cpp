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

int P;
char op[5];
int X,Y;
int father[30001];
int dis[30001];
int height[30001]; //记录以结点为根节点的集合的最大高度

int find(int x)
{
    if (father[x]==x)
        return x;

    int root=find(father[x]);
    dis[x]+=dis[father[x]];
    return father[x]=root;
}

int main()
{
    scanf("%d",&P);
    //初始化
    for (int i=1;i<=30000;i++)
    {
        father[i]=i;
        dis[i]=0;
        height[i]=1;
    }

    for (int i=0;i<P;i++)
    {
        scanf("%s",op);

        if (op[0]=='M')
        {
            scanf("%d%d",&X,&Y);
            int bot_X=find(X);
            int bot_Y=find(Y);
            father[bot_X]=bot_Y;
            int height_X=height[bot_X];
            int height_Y=height[bot_Y];
            dis[bot_X]=height_Y;
            height[bot_Y]+=height_X;
        }
        else
        {
            scanf("%d",&X);
            find(X);
            int ans=dis[X];
            printf("%d\n",ans);
        }
    }

    return 0;
}
