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

string input[4];
int num[10];

bool DFS(int num);

int main()
{
    /*�����д��ʱ�����������봦����һ���ֳ��������⣬
    ���ʹ���ַ�������������룬�����ַ�������ʱ�س���
    �ᵼ����������ݲ����룬���Ը���string����������
    ������ת����ע�⽫�ַ���ת��Ϊ10��1-9������*/

	while (cin>>input[0]>>input[1]>>input[2]>>input[3])
	{
		for (int i = 0; i<4; i++)
		{
			if (input[i]=="A")
                num[i]=1;
            else if (input[i]=="J")
                num[i]=11;
            else if (input[i]=="Q")
                num[i]=12;
            else if (input[i]=="K")
                num[i]=13;
            else if (input[i].length()==2)
                num[i]=10;
            else num[i]=input[i][0]-'0';

		}

		if (DFS(4))
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}

	return 0;
}

bool DFS(int n)
{
    //�ݹ���ֹ������������ʣ��Ԫ��Ϊһ������Ϊ24
    if (n<=1)
    {
        if (num[0]==24)
            return true;
        else return false;
    }


    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            int a=num[i],b=num[j]; //��a,b�ݴ��������������Ԫ��
            num[j]=num[n-1]; //�ѵ�ǰ���һ��Ԫ�ط��õ�j��λ��

            num[i]=a+b;
            if (DFS(n-1))
                return true;

            num[i]=a*b;
            if (DFS(n-1))
                return true;

            num[i]=a-b;
            if (DFS(n-1))
                return true;

            num[i]=b-a;
            if (DFS(n-1))
                return true;

            if (b!=0 && a%b==0)
            {
                num[i]=a/b;
                if (DFS(n-1))
                    return true;
            }

            if (a!=0 && b%a==0)
            {
                num[i]=b/a;
                if (DFS(n-1))
                    return true;
            }

            //���е�����˵���������޹�����Ҫ���ص�����֮ǰ��״̬����a.b��ֵ�黹��num[i].num[j] �ָ�����һ��״̬
            num[i]=a;
            num[j]=b;

        }
    }

    //���е�����˵��ȫ����֧�����޹�������false
    return false;
}
