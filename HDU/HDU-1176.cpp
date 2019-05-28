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
#define MAX 100000

int N;
int time_pos[100001][11]; //״̬time_pos[T][x]��ʾTʱ����x�����Ժ�ɽӵ����������

int mymax(int a, int b, int c)
{
    int m=a>b? a:b;
    return m>c? m:c;
}

//���󶯹�
void solve(int m)
{
    int M=0;
    //�Ӿ���ĵ����ڶ��㿪ʼ����
    for (int i=m-1;i>=0;i--)
    {
        //����Ҫע�ⲻ�ܰ���x=0��x=10�����������겻��������ת�Ʒ��̣���Ҫ���⴦��
        for (int j=1;j<10;j++)
        {
            time_pos[i][j]=time_pos[i][j]+mymax(time_pos[i+1][j-1],time_pos[i+1][j],time_pos[i+1][j+1]);
        }

        //��x=0��x=10���������״̬ת�Ʒ��̴���
        time_pos[i][0]+=max(time_pos[i+1][0],time_pos[i+1][1]);
        time_pos[i][10]+=max(time_pos[i+1][10],time_pos[i+1][9]);
    }

}

int main()
{
    int x,T;
    while (scanf("%d",&N) && N)
    {
        int max=1;
        memset(time_pos,0,sizeof(time_pos));
        for (int i=1;i<=N;i++)
        {
            scanf("%d%d",&x,&T);
            time_pos[T][x]++;

            //max��¼����ʱ��㣬�Ժ󶯹潫�Ӹ�ʱ��㿪ʼ
            if (T>max)
            {
                max=T;
            }
        }

        solve(max);

        int ans=time_pos[0][5]; //��ʼ���״̬pos_time[0][5]������

        printf("%d\n",ans);

    }

    return 0;
}
