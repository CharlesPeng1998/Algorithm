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

int pancake[31];
int pancake_sorted[31];
int num;
char c;

//子序列颠倒
void flip(int k)
{
    int temp;
    for (int i=1;i<=k/2;i++)
    {
        temp=pancake[k-i+1];
        pancake[k-i+1]=pancake[i];
        pancake[i]=temp;
    }
}

//第k个之前的最大饼的位置
int find_max(int k)
{
    int max=1;
    int i;
    for (i=1;i<=k;i++)
    {
        if (pancake[i]>pancake[max])
        {
            max=i;
        }
    }
    return max;
}

int main()
{
    while (~scanf("%d",&pancake[1]))
    {
        num=1;
        while ((c=getchar())!='\n')
        {
            scanf("%d",&pancake[++num]);
        }

        for (int i=1;i<=num;i++)
        {
            pancake_sorted[i]=pancake[i];
        }
        sort(pancake_sorted+1,pancake_sorted+1+num);

        for (int i=1;i<=num;i++)
        {
            printf("%d ",pancake[i]);
        }
        printf("\n");

        for (int i=num;i>=1;i--)
        {
            int biggest=find_max(i);
            if (biggest==i)
                continue;
            else
            {
                if (biggest==1)
                {
                    flip(i);
                    printf("%d ",num-i+1);
                }
                else
                {
                    flip(biggest);
                    printf("%d ",num-biggest+1);
                    flip(i);
                    printf("%d ",num-i+1);
                }
            }
        }
        printf("0\n");
    }
    return 0;
}
