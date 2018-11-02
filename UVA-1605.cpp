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

char floor_1[51][51];
char floor_2[51][51];
char country[51]={'*','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                 'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g',
                 'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x'};
int n,h,w,l;

/*��ֱ�ӵ�������ֻ��Ҫ����¥��ÿ��¥n*n,��һ��¥�ĵ�i��ȫ�����ǵ�i������
�ڶ���¥�ĵ�j�ж��ǵ�j�����ң��������ɱ�֤�ڶ���ÿһ���ϵĹ��ҷֱ����һ��
ͬһ�е�����n-1�����ҷֱ��ڽ�*/

int main()
{
    while (~scanf("%d",&n))
    {
        h=2;w=n;l=n;
        for (int i=1;i<=l;i++)
        {
            for (int j=1;j<=w;j++)
            {
                floor_1[i][j]=country[i];
            }
        }

        for (int i=1;i<=l;i++)
        {
            for (int j=1;j<=w;j++)
            {
                floor_2[i][j]=country[j];
            }
        }

        printf("%d %d %d\n",h,w,l);
        for (int i=1;i<=l;i++)
        {
            for (int j=1;j<=w;j++)
            {
                printf("%c",floor_1[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i=1;i<=l;i++)
        {
            for (int j=1;j<=w;j++)
            {
                printf("%c",floor_2[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
