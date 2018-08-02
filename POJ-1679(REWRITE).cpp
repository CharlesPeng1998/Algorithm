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

const int maxn=101;
int t,n,m;

struct Node
{
    int u,v,w;
    bool vis;
}edges[maxn*maxn];
int root[maxn];

bool cmp_edge(Node a, Node b)
{
    return a.w<b.w;
}

int findroot(int x)
{
    if (root[x]==x)
        return x;
    int px=findroot(root[x]);
    return root[x]=px;
}

int kruskal()
{
    int total=0;
    int cal=0;
    for (int i=1;i<=n;i++)
    {
        root[i]=i;
    }
    int i;
    for (i=1;i<=m;i++)
    {
        int px=findroot(edges[i].u);
        int py=findroot(edges[i].v);
        if (px==py)
            continue;
        else
        {
            edges[i].vis=1;
            total+=edges[i].w;
            root[px]=py;
            cal++;
            if (cal==n-1)
                break;
        }
    }
    return total;
}

int kruskal(int k)
{
    int total=0;
    int cal=0;
    for (int i=1;i<=n;i++)
    {
        root[i]=i;
    }
    int i;
    for (i=1;i<=m;i++)
    {
        if (i==k) continue;
        int px=findroot(edges[i].u);
        int py=findroot(edges[i].v);
        if (px==py)
            continue;
        else
        {
            total+=edges[i].w;
            root[px]=py;
            cal++;
            if (cal==n-1)
                break;
        }
    }
    if (i>m) return -1;
    else return total;
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
        }
        sort(edges+1,edges+1+m,cmp_edge);
        for (int i=1;i<=m;i++)
            edges[i].vis=0;
        int MSF=kruskal();

        bool unique=1;
        int SecMSF;
        for (int i=1;i<=m;i++)
        {
            if (edges[i].vis)
            {
                SecMSF=kruskal(i);
                if (SecMSF==MSF)
                {
                    unique=0;
                    break;
                }
            }
        }
        if (unique)
            printf("%d\n",MSF);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
