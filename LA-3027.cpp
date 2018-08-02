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

int T,N;
char op;
int I,J;
int father[200001];
int dis[200001];

int find(int x)
{
    if (father[x]==x)
        return x;

    //递归找到根节点
    int root=find(father[x]);
    //更新该结点到根节点的距离
    dis[x]+=dis[father[x]];
    //路径压缩处理
    //将该结点直接连接到根节点
    //减少查询的复杂度
    father[x]=root;

    return father[x];
}

int main()
{
    cin>>T;
    while (T--)
    {
        cin>>N;

        //初始化
        for (int i=1;i<=N;i++)
        {
            father[i]=i;
            dis[i]=0;
        }

        while (cin>>op)
        {
            if (op=='O')
                break;
            else if (op=='E')
            {
                cin>>I;
                find(I);
                cout<<dis[I]<<endl;
            }
            else if (op=='I')
            {
                cin>>I>>J;
                father[I]=J;
                dis[I]=abs(I-J)%1000;
            }
        }
    }

    return 0;
}
