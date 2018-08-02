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
string op;
int p,q,v;

struct Node
{
    int value;
    int father;
};

struct Query
{
    char op;
    int p,q,v,k,px[15];

}query[40001];

Node num[20001]; //结点存储值和父亲节点的序号
int dis[20001]; //dis[i]表示结点i到父亲结点的距离

//debug用
void print()
{
    for (int i=0;i<n;i++)
    {
        printf("Num %d: father is %d, value is %d, distance to father is %d\n",i,num[i].father,num[i].value,dis[i]);
    }
}

//寻找根节点，并作路径压缩
int find(int x)
{
    if (num[x].father==x)
    {
        return x;
    }

    int root=find(num[x].father);
    dis[x]^=dis[num[x].father];
    return num[x].father=root;
}

bool insert()
{
    if (find(p)==find(q))
    {
        //p,q属于同一个集合
        if ((dis[p]^dis[q])!=v)
            return false;
        else
        {
            if (num[p].value>=0 && num[q].value<0)
            {
                num[q].value=v^num[p].value;
            }
            else if (num[q].value>=0 && num[p].value<0)
            {
                num[p].value=v^num[q].value;
            }

            return true;
        }
    }
    else
    {
        if (num[p].value>=0 && num[q].value<0)
        {
            num[q].value=v^num[p].value;
        }
        else if (num[q].value>=0 && num[p].value<0)
        {
            num[p].value=v^num[q].value;
        }

        //二者不在同一个集合则插入同一个集合
        //应该将p,q的根节点相连
        dis[num[p].father]=v^dis[p]^dis[q];
        num[num[p].father].father=num[q].father;
        return true;
    }
}

void init()
{
    for (int i=0;i<n;i++)
    {
        num[i].value=-1; //各结点的值初始化为-1代表未知
        num[i].father=i; //父亲节点为其本身
        dis[i]=0;
    }

    //print();

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
                query[i].q=-1;
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
    int num_I=0;
    //逐条指令进行处理
    for (int i=0;i<Q;i++)
    {
        if (query[i].op=='I')
        {
            num_I++;
            if (query[i].q==-1)
            {
                p=query[i].p;
                v=query[i].v;

                if (num[p].value!=v && num[p].value>=0)
                {
                    printf("The first %d facts are conflicting.\n",num_I);
                    return;
                }
                else
                {
                    num[p].value=v; //作修改结点值的操作
                    //某个结点的值已知，还可以推出其父亲结点的值
                    num[num[p].father].value=num[p].value^dis[p];
                }
            }
            else
            {
                p=query[i].p;
                q=query[i].q;
                v=query[i].v;

                //作插入集合的操作
                if (!insert())
                {
                    printf("The first %d facts are conflicting.\n",num_I);
                    return ;
                }
            }

            //print();
        }
        else if (query[i].op=='Q')
        {
            int res=0;
            bool flag=1;

            for (int j=0;j<query[i].k;j++)
            {
                int target;
                bool found=0;

                if (query[i].px[j]>=0)
                {
                    for (int k=j+1;k<query[i].k;k++)
                    {
                        if (query[i].px[k]>=0 && find(query[i].px[j])==find(query[i].px[k]))
                        {
                            target=k;
                            found=1;
                            break;
                        }
                    }

                    if (found)
                    {
                        res^=dis[query[i].px[j]]^dis[query[i].px[target]];
                        query[i].px[target]=-1;
                        query[i].px[j]=-1;
                    }
                    else
                    {
                        if (num[query[i].px[j]].value>=0)
                        {
                            res^=num[query[i].px[j]].value;
                            query[i].px[j]=-1;
                        }
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                }
            }
            if (flag)
            {
                cout<<res<<endl;
            }
            else printf("I don't know.\n");
        }
    }
}

int main()
{
    int count=1;
    while (scanf("%d%d",&n,&Q))
    {
        if (n==0 && Q==0)
            break;

        init(); //初始化集合，并进行数据输入
        printf("Case %d:\n", count);
        count++;
        solve();
        printf("\n");
    }

    return 0;
}
