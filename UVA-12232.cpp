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
int vis[20001]; //在Q指令中用来记录属于同一集合的数的数量的奇偶

struct Query
{
    char op;
    int p,q,v,k,px[15];

}query[40001];

//寻找根节点，并作路径压缩
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
    //找p,q两数的根节点
    int pa=find(p);
    int pb=find(q);

    //下面的操作为使pa的父亲结点为pb
    //但我们希望虚结点n永远为根节点
    //因此若pa的根节点为n，则需要交换pa,pb的值
    //使得pb的父亲结点指向pa
    if (pa==n)
    {
        swap(pa,pb);
    }
    if (pa==pb)
    {
        //pa,pb属于同一个集合
        //判断是否冲突
        if ((dis[p]^dis[q])!=v) //异或运算最好带括号
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
    //本题的输入需要做一些处理
    //先用一个query数组接收所有输入
    //随后再逐条处理
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
    int num_I=0; //记录指令I的数量，后面输出冲突需要
    //逐条指令进行处理
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

            //检查要求计算的数当中，属于同一个集合（根节点相同）的个数额奇偶
            //若为奇数，则最终的结果不可计算
            //为偶数则可计算
            for (int j=0;j<query[i].k;j++)
            {
                int px=find(query[i].px[j]);
                ans^=dis[query[i].px[j]];
                //统计根节点非虚拟结点的
                //虚拟结点集合当中的数都是可算的
                if (px!=n)
                    vis[px]^=1; //vis[px]为1则说明属于根节点px的数的数量为奇数个
            }

            for (int j=0;j<query[i].k;j++)
            {
                //注意这里检查的是j的根节点
                //不是j
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
