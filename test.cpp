
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>

#define MAX 103
using namespace std;

struct edge{
    int u;
    int v;
    int w;
};

edge array[MAX*MAX];
int fa[MAX],n,m;
bool tag[MAX*MAX];

bool cmp(edge a,edge b)
{
    if(a.w!=b.w) return a.w<b.w;
    if(a.u!=b.u) return a.u<b.u;
    return a.v<b.v;
}

int find(int a)
{
    if(fa[a]!=a) fa[a]=find(fa[a]);
    return fa[a];
}

int kruskal(int p)                 //amount记录生成树的边的条数 ,mstw表示去除标号为m的最小生成树的权值之和
{
    int i,amount=0,mstw=0,fu,fv;
    for(i=0;i<m;i++)
    {
       if(i==p) continue;
       fu=find(array[i].u);
       fv=find(array[i].v);
       if(fu==fv) continue;

       fa[fu]=fv;
       mstw+=array[i].w;
       amount++;
       if(amount==n-1) break;
    }
    if(i==m) return -1;
    //为什么这个是判断不存在mst的条件   // 如果不存在mst，则返回-1
    else return mstw;
}

int kruskal()                 //amount记录生成树的边的条数 ,mstw表示去除标号为m的最小生成树的权值之和
{
    int i,amount=0,mstw=0,fu,fv;
    for(i=0;i<m;i++)
    {
       fu=find(array[i].u);
       fv=find(array[i].v);
       if(fu==fv) continue;

       fa[fu]=fv;
       mstw+=array[i].w;
       tag[i]=true;
       amount++;
       if(amount==n-1) break;
    }
    return mstw;
}

int main()
{
    int i,j,k,t,u,v,w,ans,sec_mstw; //sec_mstw表示次小生成树的权值之和
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            array[i].u=u;
            array[i].v=v;
            array[i].w=w;
        }
        sort(array,array+m,cmp);

        for(i=0;i<=n;i++) fa[i]=i;
        memset(tag,false,sizeof(tag));
        ans=kruskal();

        for(i=0;i<m;i++)
        {
           if(tag[i])
           {
               for(j=0;j<=n;j++) fa[j]=j;
               sec_mstw=kruskal(i);
               if(sec_mstw==ans) break;
           }
        }

        if(i<m) printf("Not Unique!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
