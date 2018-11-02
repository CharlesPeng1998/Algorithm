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

//��
struct Node
{
    int from; //���
    int to; //�յ�
    int w; //Ȩֵ
    bool vis; //��kruscal�㷨���Ƿ�ʹ�ù�
};
Node Edges[MAXM];

bool cmp(Node a, Node b)
{
    return a.w<b.w;
}

//��ʽǰ����
struct Node1
{
    int to; //�ߵ��յ�
    int next; //��һ���ߵ�λ��
};
Node1 Vertex[MAXN];

int N,M;
int head[MAXN]; //�ڽӱ�ͷ���λ��
int End[MAXN]; //�ڽӱ�β�ڵ�λ�ã�����ϲ�
int Len[MAXN][MAXN]; //ͼ������֮������С��������·������ı�

void kruscal()
{
    int x,y,k=0;

    //��ʼ���ڽӱ�ÿ������ʼ��ʱ�����һ��ָ���Լ��ıߣ���ʾ���i����Ϊһ������
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
            //�������������ڵļ���
            for (int w=head[x];w!=-1;w=Vertex[w].next)
            {
                for (int v=head[y];v!=-1;v=Vertex[v].next)
                {
                    Len[Vertex[w].to][Vertex[v].to]=Len[Vertex[v].to][Vertex[w].to]=Edges[i].w;\
                    //��ǰ����ı�һ���Ǽ�(x,y)�߳ɻ���ɾȥ�ĳ�(x,y)�ⳤ�����ı�
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
        MST=0; //��С����������
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
