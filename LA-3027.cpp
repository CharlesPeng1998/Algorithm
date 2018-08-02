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

int T,N;
char op;
int I,J;
int father[200001];
int dis[200001];

int find(int x)
{
    if (father[x]==x)
        return x;

    //�ݹ��ҵ����ڵ�
    int root=find(father[x]);
    //���¸ý�㵽���ڵ�ľ���
    dis[x]+=dis[father[x]];
    //·��ѹ������
    //���ý��ֱ�����ӵ����ڵ�
    //���ٲ�ѯ�ĸ��Ӷ�
    father[x]=root;

    return father[x];
}

int main()
{
    cin>>T;
    while (T--)
    {
        cin>>N;

        //��ʼ��
        for (int i=1;i<=N;i++)
        {
            father[i]=i;
            dis[i]=0;
        }

        while (cin>>op)
        {
            if (op=='O')
                break;
            else if (op=='E')
            {
                cin>>I;
                find(I);
                cout<<dis[I]<<endl;
            }
            else if (op=='I')
            {
                cin>>I>>J;
                father[I]=J;
                dis[I]=abs(I-J)%1000;
            }
        }
    }

    return 0;
}
