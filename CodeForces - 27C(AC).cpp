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
using namespace std;

int N;
int num[100001];



int main()
{
  while (cin>>N)
  {
		int one=1;
		int two;
		int three;
    bool exist_flag=0;

    for (int i=1;i<=N;i++)
    {
      cin>>num[i];
    }

    for (int i=2;i<=N;i++)
    {
      if (num[i]>num[i-1])
      {
        two=i;
        for (int j=i+1;j<=N;j++)
        {
					if (num[j]<num[two])
					{
						three=j;
						exist_flag=1;
						break;
					}
				}
      }
			else if (num[i]<num[i-1])
			{
				two=i;
				for (int j=i+1;j<=N;j++)
				{
					if (num[j]>num[two])
					{
						three=j;
						exist_flag=1;
						break;
					}
				}
			}
			else
			{
				one++;
			}

			if (exist_flag)
				break;
    }

		if (exist_flag)
		{
			cout<<'3'<<endl;
			cout<<one<<' '<<two<<' '<<three<<endl;
		}
		else
		{
			cout<<'0'<<endl;
		}
  }

	return 0;
}
