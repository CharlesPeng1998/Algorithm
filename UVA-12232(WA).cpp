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

Node num[20001]; //���洢ֵ�͸��׽ڵ�����
int dis[20001]; //dis[i]��ʾ���i�����׽��ľ���

//Ѱ�Ҹ��ڵ㣬����·��ѹ��
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
        //p,q����ͬһ������
        if ((dis[p]^dis[q])!=v)
            return false;
        else return true;
    }
    else
    {
        //���߲���ͬһ�����������ͬһ������
        //Ӧ�ý�p,q�ĸ��ڵ�����
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

        //����I�����
        int num_I=0;

        for (int i=0;i<n;i++)
        {
            num[i].value=-1; //������ֵ��ʼ��Ϊ-1����δ֪
            num[i].father=i; //���׽ڵ�Ϊ�䱾��
            dis[i]=0;
        }

        for (int i=0;i<Q;i++)
        {
            //��Ҫ���ַ���������
            //�س���̫���׵�����������
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
                        num[p].value=v; //���޸Ľ��ֵ�Ĳ���
                        //ĳ������ֵ��֪���������Ƴ��丸�׽���ֵ
                        num[num[p].father].value=num[p].value^dis[p];
                    }
                }
                else if (inputs.capacity()==4)
                {
                    p=inputs[0];
                    q=inputs[1];
                    v=inputs[2];

                    //�����뼯�ϵĲ���
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
