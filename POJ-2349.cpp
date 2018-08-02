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
int cal;
int s,p;
struct Point
{
    int x,y;
}points[501];

struct Edge
{
    int u,v;
    double distance;
}edges[501*501];

double dis[501];
int root[501];

double get_dis(Point a,Point b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}

bool cmp_edge(Edge a, Edge b)
{
    return a.distance<b.distance;
}

void read()
{
    for (int i=1;i<=p;i++)
    {
        scanf("%d%d",&points[i].x,&points[i].y);
    }

    for (int i=1;i<=p;i++)
    {
        root[i]=i;
    }

    //�������γɵ���ȫͼ�ı߰���Ȩֵ��С��������
    cal=0;
    for (int i=1;i<p;i++)
    {
        for (int j=i+1;j<=p;j++)
        {
            edges[++cal].u=i;
            edges[cal].v=j;
            edges[cal].distance=get_dis(points[i],points[j]);
        }
    }
    sort(edges+1,edges+1+cal,cmp_edge);
}

int findroot(int x)
{
    if (root[x]==x)
        return x;
    int px=findroot(root[x]);
    return root[x]=px;
}

bool cmp_double(double a,double b)
{
    return a>b;
}

void kruscal()
{
    //kruscal�㷨��
    //�����߰���Ȩֵ��С��������
    //��������˳������ߵĽ��
    //������ͬһ����������������ϲ�Ϊһ����
    memset(dis,0.0,sizeof(dis));
    int sum=0;
    for (int i=1;i<=cal;i++)
    {
        int px=findroot(edges[i].u);
        int py=findroot(edges[i].v);

        if (px==py)
            continue;
        else
        {
            root[px]=py;
            dis[++sum]=edges[i].distance;

            if (sum==p-1)
                break;
        }
    }

    //����С�������е�Ȩֵ�Ӵ�С����
    //�����豸�������ϴ�ģ�s�������豸������s-1����
    //���dis[s]��Ϊ�����豸�����ߺ�ʣ�µ����ߣ���Ϊ����D
    sort(dis+1,dis+sum+1,cmp_double);
    printf("%.2f\n",dis[s]);
}


int main()
{
    scanf("%d",&N);
    while (N--)
    {
        scanf("%d%d",&s,&p);
        read();
        kruscal();
    }

    return 0;
}
