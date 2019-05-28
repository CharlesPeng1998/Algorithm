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
    /*最初编写的时候在数据输入处理这一部分出现了问题，
    最初使用字符数组来存放输入，但是字符的输入时回车键
    会导致输入的数据不理想，所以改用string数组存放输入
    并进行转换。注意将字符串转换为10和1-9的区别。*/

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
    //递归终止条件：数组中剩余元素为一个并且为24
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
            int a=num[i],b=num[j]; //用a,b暂存用来运算的两个元素
            num[j]=num[n-1]; //把当前最后一个元素放置到j的位置

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

            //进行到这里说明该搜索无果，需要返回到搜索之前的状态。将a.b的值归还给num[i].num[j] 恢复到上一个状态
            num[i]=a;
            num[j]=b;

        }
    }

    //进行到这里说明全部分支搜索无果，返回false
    return false;
}
