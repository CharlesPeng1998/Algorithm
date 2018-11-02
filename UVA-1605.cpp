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

/*最直接的做法，只需要两层楼，每层楼n*n,第一层楼的第i行全部都是第i个国家
第二层楼的第j列都是第j个国家，这样即可保证第二层每一列上的国家分别与第一层
同一列的另外n-1个国家分别邻接*/

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
