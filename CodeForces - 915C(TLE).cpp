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

long long A;
long long B;
stack<int> temp;
int length_A;
int length_B;
int digit_A[20];
int digit_B[20];
int mark_A[20];
int convert_A[20];

bool judge(int n)
{
	for (int i=1;i<=n;i++)
	{
		if (convert_A[i]<digit_B[i])
		return true; //����true��ʾС��
	}

	return false;
}

bool myfunction(int i, int j)
{
	return i>j;
}

bool convert(int digit_num)
{
	if (digit_num>length_B)
	{
		return true;
	}

	for (int i=1;i<=length_A;i++)
	{
		if ((judge(digit_num-1) && !mark_A[i]) || (!judge(digit_num-1) && digit_A[i]<=digit_B[digit_num] && !mark_A[i]))
		{
			mark_A[i]=1;
			convert_A[digit_num]=digit_A[i];
			if (convert(digit_num+1))
			{
				//����ݹ���غ���Ϣ�򷵻�true
				return true;
			}
			else
			{
				//û�д��غ���Ϣ����Ҫ�ظ�״̬������һ�γ���
				mark_A[i]=0;
			}
		}
	}

	//�ߵ�������˵��ʧ��
	return false;
}

int main()
{
	int temp;
	while(cin>>A>>B)
	{
		length_A=0;
		length_B=0;
		/*��AB�����ĸ�λ�洢�����鵱��*/
		while (A!=0)
		{
			digit_A[++length_A]=A%10;
			A/=10;
		}

		while (B!=0)
		{
			digit_B[++length_B]=B%10;
			B/=10;
		}

		for (int i=1;i<=length_B/2;i++)
		{
			temp=digit_B[i];
			digit_B[i]=digit_B[length_B-i+1];
			digit_B[length_B-i+1]=temp;
		}

		for (int i=1;i<=length_A;i++)
		{
			mark_A[i]=0;
			convert_A[i]=0;
		}

		if (length_A<length_B)
		{
			sort(digit_A+1,digit_A+length_A+1,myfunction);

			for (int i=1;i<=length_A;i++)
			{
				convert_A[i]=digit_A[i];
			}
		}
		else
		{
			sort(digit_A+1,digit_A+length_A+1,myfunction);
			convert(1);
		}

		for (int i=1;i<=length_A;i++)
		{
			cout<<convert_A[i];
		}
		cout<<endl;
	}

	return 0;
}
