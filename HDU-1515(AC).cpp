//谨记：不要对new的数组用memset！！！！！！ 



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

//深度优先搜索
void DFS(stack<char>& orig, int orig_curr, int con_curr, bool* stat, int str_len,int stat_curr)
{
	//用字符串转化完成作为结束的条件，即con_ptr指向'\0'
	if (con_str[con_curr]=='\0')
	{
		//转换完成后则根据标记状态数组打印出入栈的步骤
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
			orig.push(last_pop); //刚才出栈的元素需要重新入栈
			stat[stat_curr]=false;
		}
		
		return ;
	}
	
	orig.push(orig_str[orig_curr]);
	DFS(orig,orig_curr+1,con_curr,stat,str_len,stat_curr+1);
	orig.pop();//刚才入栈的要重新出栈 
	
	//若当前栈顶元素与指针所指字符匹配，则可以考虑出栈 
	if (!orig.empty() && orig.top()==con_str[con_curr])
	{
		char last_pop=orig.top();
		orig.pop();
		stat[stat_curr]=true; //标记数组置1说明出栈 
		DFS(orig,orig_curr,con_curr+1,stat,str_len,stat_curr+1); //递归对下一个结点进行相同操作 
		orig.push(last_pop); //刚才出栈的元素需要重新入栈 
		stat[stat_curr]=false;
	}
	
	
} 

int main()
{
	while (cin>>orig_str>>con_str)
	{
		stack<char> orig;
		char next;
	
		bool *stat=new bool[2*orig_str.length()];//这个用来进行状态标记，即确定每一步是入栈还是出栈
	
		for (int i=0;i<2*orig_str.length();i++)
		{
			stat[i]=false;
		}
	 
		int con_curr=0;
		int orig_curr=1;
		int stat_curr=1;
	
		//第一个字符肯定得先入栈的吧
		orig.push(orig_str[0]);
		stat[0]=0;
		cout<<'['<<endl;
		DFS(orig,orig_curr,con_curr,stat,orig_str.length(),stat_curr);
		cout<<']'<<endl;
		delete[] stat;
	}
	return 0;
}




