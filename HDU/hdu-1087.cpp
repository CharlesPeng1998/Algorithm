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

int N;
int num[1001];
int dp[1001]; //dp[i]��ʾ��iΪβԪ�صĵ��������е�����

void solve()
{
    //dp[i]��ʼΪnum[i]
    for (int i=1;i<=N;i++)
    {
        dp[i]=num[i];
    }

    for (int i=2;i<=N;i++)
    {
        for (int j=1;j<i;j++)
        {
            if (num[i]>num[j])
            {
                dp[i]=max(dp[i],dp[j]+num[i]); //״̬ת�Ʒ���
                //�޸�ǰ:dp[i]=max(num[i],dp[j]+num[i]);
            }
        }
    }
}

int main()
{
    while (scanf("%d",&N) && N)
    {
        for (int i=1;i<=N;i++)
        {
            scanf("%d",&num[i]);
        }

        solve();

        int ans=-INF;
        for (int i=1;i<=N;i++)
        {
            if (dp[i]>ans)
            {
                ans=dp[i];
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
