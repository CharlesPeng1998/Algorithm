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

int n,Q;
int p,q,v;
int father[20001];
int dis[20001];
int vis[20001]; //��Qָ����������¼����ͬһ���ϵ�������������ż

struct Query
{
    char op;
    int p,q,v,k,px[15];

}query[40001];

//Ѱ�Ҹ��ڵ㣬����·��ѹ��
int find(int x)
{
    if (father[x]==x)
    {
        return x;
    }

    int root=find(father[x]);
    dis[x]^=dis[father[x]];
    return father[x]=root;
}

bool insert()
{
    //��p,q�����ĸ��ڵ�
    int pa=find(p);
    int pb=find(q);

    //����Ĳ���Ϊʹpa�ĸ��׽��Ϊpb
    //������ϣ������n��ԶΪ���ڵ�
    //�����pa�ĸ��ڵ�Ϊn������Ҫ����pa,pb��ֵ
    //ʹ��pb�ĸ��׽��ָ��pa
    if (pa==n)
    {
        swap(pa,pb);
    }
    if (pa==pb)
    {
        //pa,pb����ͬһ������
        //�ж��Ƿ��ͻ
        if ((dis[p]^dis[q])!=v) //���������ô�����
            return false;
        else return true;
    }
    else
    {
        dis[pa]=v^dis[p]^dis[q];
        father[pa]=pb;
        return true;
    }
}

void init()
{
    //�����������Ҫ��һЩ����
    //����һ��query���������������
    //�������������
    for (int i=0;i<=n;i++)
    {
        father[i]=i;
        dis[i]=0;
    }

    int a,b,c;
    char temp[105];
    for (int i=0;i<Q;i++)
    {
        scanf("%s",temp);
        if ((query[i].op=temp[0])=='I')
        {
            gets(temp);
            if (sscanf(temp,"%d%d%d",&a,&b,&c)==2)
            {
                query[i].p=a;
                query[i].q=n;
                query[i].v=b;
            }
            else
            {
                query[i].p=a;
                query[i].q=b;
                query[i].v=c;
            }
        }
        else
        {
            scanf("%d",&query[i].k);
            for (int j=0;j<query[i].k;j++)
            {
                scanf("%d",&query[i].px[j]);
            }
        }
    }
}

void solve()
{
    int num_I=0; //��¼ָ��I�����������������ͻ��Ҫ
    //����ָ����д���
    for (int i=0;i<Q;i++)
    {
        if (query[i].op=='I')
        {
            num_I++;
            p=query[i].p;
            q=query[i].q;
            v=query[i].v;
            if(!insert())
            {
                printf("The first %d facts are conflicting.\n",num_I);
                return;
            }
        }
        else if (query[i].op=='Q')
        {
            int ans=0;
            bool flag=1;

            //���Ҫ�����������У�����ͬһ�����ϣ����ڵ���ͬ���ĸ�������ż
            //��Ϊ�����������յĽ�����ɼ���
            //Ϊż����ɼ���
            for (int j=0;j<query[i].k;j++)
            {
                int px=find(query[i].px[j]);
                ans^=dis[query[i].px[j]];
                //ͳ�Ƹ��ڵ���������
                //�����㼯�ϵ��е������ǿ����
                if (px!=n)
                    vis[px]^=1; //vis[px]Ϊ1��˵�����ڸ��ڵ�px����������Ϊ������
            }

            for (int j=0;j<query[i].k;j++)
            {
                //ע�����������j�ĸ��ڵ�
                //����j
                if (vis[father[query[i].px[j]]])
                    flag=0;
                vis[father[query[i].px[j]]]=0;
            }

            if (flag)
            {
                printf("%d\n",ans);
            }
            else printf("I don't know.\n");
        }
    }
}

int main()
{
    int count=1;
    while(scanf("%d%d",&n,&Q))
    {
        if (n==0 && Q==0)
            break;

        init();
        printf("Case %d:\n",count);
        count++;
        solve();
        printf("\n");
    }
    return 0;

}
