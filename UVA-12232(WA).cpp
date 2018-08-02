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
int px[15];

struct Node
{
    int value;
    int father;
};

Node num[20001]; //结点存储值和父亲节点的序号
int dis[20001]; //dis[i]表示结点i到父亲结点的距离

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
        else return true;
    }
    else
    {
        //二者不在同一个集合则插入同一个集合
        //应该将p,q的根节点相连
        dis[num[p].father]=v^dis[p]^dis[q];
        num[num[p].father].father=num[q].father;
        return true;
    }
}

int main()
{
    int count=1;
    while (scanf("%d%d",&n,&Q))
    {
        bool over=0;
        if (n==0 && Q==0)
            break;

        printf("Case %d:\n",count);
        count++;

        //操作I的序号
        int num_I=0;

        for (int i=0;i<n;i++)
        {
            num[i].value=-1; //各结点的值初始化为-1代表未知
            num[i].father=i; //父亲节点为其本身
            dis[i]=0;
        }

        for (int i=0;i<Q;i++)
        {
            //不要用字符来输入了
            //回车键太容易导致意外输入
            cin>>op;

            if (op=="I")
            {
                num_I++;
                int temp;
                vector<int> inputs;
                cin>>temp;
                inputs.push_back(temp);
                while (cin.get()!='\n')
                {
                    cin>>temp;
                    inputs.push_back(temp);
                }

                if (over)
                    continue;

                if (inputs.capacity()==2)
                {
                    p=inputs[0];
                    v=inputs[1];

                    if (num[p].value!=v && num[p].value>=0)
                    {
                        printf("The first %d facts are conflicting.\n",num_I);
                        over=1;
                    }
                    else
                    {
                        num[p].value=v; //作修改结点值的操作
                        //某个结点的值已知，还可以推出其父亲结点的值
                        num[num[p].father].value=num[p].value^dis[p];
                    }
                }
                else if (inputs.capacity()==4)
                {
                    p=inputs[0];
                    q=inputs[1];
                    v=inputs[2];

                    //作插入集合的操作
                    if (!insert())
                    {
                        printf("The first %d facts are conflicting.\n",num_I);
                        over=1;
                    }
                }
            }

            if (op=="Q")
            {
                memset(px,-1,sizeof(px));
                int t;
                int res=0;
                bool flag=1;

                scanf("%d",&t);
                for (int j=0;j<t;j++)
                {
                    scanf("%d",&px[j]);
                }

                if (over)
                    continue;

                for (int j=0;j<t;j++)
                {
                    int target;
                    bool found=0;

                    if (px[j]>=0)
                    {
                        for (int k=j+1;k<t;k++)
                        {
                            if (px[k]>=0 && find(px[j])==find(px[k]))
                            {
                                target=k;
                                found=1;
                                break;
                            }
                        }

                        if (found)
                        {
                            res^=dis[px[j]]^dis[px[target]];
                            px[target]=-1;
                            px[j]=-1;
                        }
                        else
                        {
                            if (num[px[j]].value>=0)
                            {
                                res^=num[px[j]].value;
                                px[j]=-1;
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
        printf("\n");
    }
    return 0;
}
