//���ǣ���Ҫ��new��������memset������������ 



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

string orig_str;
string con_str;

//�����������
void DFS(stack<char>& orig, int orig_curr, int con_curr, bool* stat, int str_len,int stat_curr)
{
	//���ַ���ת�������Ϊ��������������con_ptrָ��'\0'
	if (con_str[con_curr]=='\0')
	{
		//ת����ɺ�����ݱ��״̬�����ӡ����ջ�Ĳ���
		for (int i=0;i<2*str_len;i++)
		{
			if (stat[i])
			{
				cout<<"o ";
			}
			else
			{
				cout<<"i ";
			}
		}
		cout<<endl;
		
		return;
	}
	
	if (orig_str[orig_curr]=='\0')
	{
		if (!orig.empty() && orig.top()==con_str[con_curr])
		{
			char last_pop=orig.top();
			orig.pop();
			stat[stat_curr]=true; 
			DFS(orig,orig_curr,con_curr+1,stat,str_len,stat_curr+1); 
			orig.push(last_pop); //�ղų�ջ��Ԫ����Ҫ������ջ
			stat[stat_curr]=false;
		}
		
		return ;
	}
	
	orig.push(orig_str[orig_curr]);
	DFS(orig,orig_curr+1,con_curr,stat,str_len,stat_curr+1);
	orig.pop();//�ղ���ջ��Ҫ���³�ջ 
	
	//����ǰջ��Ԫ����ָ����ָ�ַ�ƥ�䣬����Կ��ǳ�ջ 
	if (!orig.empty() && orig.top()==con_str[con_curr])
	{
		char last_pop=orig.top();
		orig.pop();
		stat[stat_curr]=true; //���������1˵����ջ 
		DFS(orig,orig_curr,con_curr+1,stat,str_len,stat_curr+1); //�ݹ����һ����������ͬ���� 
		orig.push(last_pop); //�ղų�ջ��Ԫ����Ҫ������ջ 
		stat[stat_curr]=false;
	}
	
	
} 

int main()
{
	while (cin>>orig_str>>con_str)
	{
		stack<char> orig;
		char next;
	
		bool *stat=new bool[2*orig_str.length()];//�����������״̬��ǣ���ȷ��ÿһ������ջ���ǳ�ջ
	
		for (int i=0;i<2*orig_str.length();i++)
		{
			stat[i]=false;
		}
	 
		int con_curr=0;
		int orig_curr=1;
		int stat_curr=1;
	
		//��һ���ַ��϶�������ջ�İ�
		orig.push(orig_str[0]);
		stat[0]=0;
		cout<<'['<<endl;
		DFS(orig,orig_curr,con_curr,stat,orig_str.length(),stat_curr);
		cout<<']'<<endl;
		delete[] stat;
	}
	return 0;
}




