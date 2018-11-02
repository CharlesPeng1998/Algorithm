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
const int MAXN=1010;
const int MAXM=100010;

int father[MAXN];

int find(int x)
{
    if (x!=father[x])
        father[x]=find(father[x]);
    return father[x];
}

//边
struct Node
{
    int from; //起点
    int to; //终点
    int w; //权值
    bool vis; //在kruscal算法中是否使用过
};
Node Edges[MAXM];

bool cmp(Node a, Node b)
{
    return a.w<b.w;
}

//链式前向星
struct Node1
{
    int to; //边的终点
    int next; //下一条边的位置
};
Node1 Vertex[MAXN];

int N,M;
int head[MAXN]; //邻接表头结点位置
int End[MAXN]; //邻接表尾节点位置，方便合并
int Len[MAXN][MAXN]; //图中两点之间在最小生成树上路径上最长的边

void kruscal()
{
    int x,y,k=0;

    //初始化邻接表，每个结点初始的时候添加一条指向自己的边，表示结点i各自为一个集合
    memset(head,-1,sizeof(head));
    memset(End,-1,sizeof(End));
    for (int i=1;i<=N;i++)
    {
        Vertex[i].to=i;
        Vertex[i].next=head[i]; //-1
        End[i]=i;
        head[i]=i;
    }

    sort(Edges,Edges+M,cmp);
    for (int i=0;i<M;i++)
    {
        if (k==N-1)
            break;
        if (Edges[i].w<0)
            continue;
        x=find(Edges[i].from);
        y=find(Edges[i].to);
        if (x!=y)
        {
            //遍历两个点所在的集合
            for (int w=head[x];w!=-1;w=Vertex[w].next)
            {
                for (int v=head[y];v!=-1;v=Vertex[v].next)
                {
                    Len[Vertex[w].to][Vertex[v].to]=Len[Vertex[v].to][Vertex[w].to]=Edges[i].w;\
                    //当前加入的边一定是加(x,y)边成环后删去的除(x,y)外长度最大的边
                }
            }
            Vertex[End[y]].next=head[x];
            head[x]=head[y];
            End[y]=End[x];
            father[y]=x;
            k++;
            Edges[i].vis=true;
        }
    }
}

int main()
{
    int T,x,y,w;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++)
        {
            father[i]=i;
        }
        memset(Len,0x7f,sizeof(Len));
        for (int i=0;i<M;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            Edges[i].from=x;
            Edges[i].to=y;
            Edges[i].w=w;
            Edges[i].vis=false;
        }

        int MST,SecMST;
        kruscal();
        MST=0; //最小生成树长度
        for (int i=0;i<M;i++)
        {
            if (Edges[i].vis)
                MST+=Edges[i].w;
        }
        SecMST=0xfffff0;
        for (int i=0;i<M;i++)
        {
            if (!Edges[i].vis)
                SecMST=min(SecMST,MST+Edges[i].w-Len[Edges[i].from][Edges[i].to]);
        }
        if (SecMST==MST)
        {
            printf("Not Unique!\n");
        }
        else
        {
            printf("%d\n",MST);
        }
    }
    return 0;
}
