#include<iostream>
#include<memory.h>
using namespace std;

int gra[100][100];
int len[100];//从该点开始的最长路径长度
int n;

struct mat
{
    int a,b;
};

//动态规划求DAG上的最长路径
//用len数组记录各节点出发的最长路径，初始均为0
//各结点的状态为len[i]
//状态转移方程：len[i]=max(len[i],len[j]+1)
//该函数采用了避免重复计算的递归：记忆化搜索
int f(int pos)
{
    //len[pos]大于零说明已计算过，直接返回结果，避免重复计算
    if(len[pos] > 0)
    {
        return len[pos];
    }
    //未计算过的结点，其最长路径初始为1
    len[pos] = 1;

    //开始利用状态转移方程求最长路径
    for(int i = 0; i < n; i ++)
    {
        if(gra[pos][i])
        {
            len[pos] = max(len[pos], f(i) + 1);
        }
    }
    return len[pos];
}

//使得编号字典序最小的编号打印
//同样使用了递归
void print(int i)
{
    cout << i << ' ';

    //从低到高遍历编号寻找满足二元关系和状态转移的下一个结点
    //再对找到的下一个结点做相同的操作
    for(int j = 0; j < n; j ++)
    {
        if(gra[i][j] && len[i] == len[j] + 1)
        {
            print(j);
            break;
        }
    }
}

int main()
{
    int ans = -1;
    cin >> n;
    mat nod[100];
    memset(gra, 0, sizeof(gra));
    memset(len, 0, sizeof(len));
    for(int i = 0; i < n; i ++)
    {
        cin >> nod[i].a >> nod[i].b;
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            if((nod[i].a < nod[j].a && nod[i].b < nod[j].b) || (nod[i].a < nod[j].b && nod[i].b < nod[j].a))
            {
                gra[i][j] = 1;//用二维数组标记所有具有可嵌套二元关系的[i,j]
            }
        }
    }
    int matid = 0;
    for(int i = 0; i < n; i ++)
    {
        //从每一个结点开始求最长路径
        if(f(i) > ans)
        {
            ans = f(i);
            matid = i;//记录最大路径的首结点ID，打印ID需要
        }
    }
    cout << ans << endl;
    print(matid); //按字典序最小打印路径上结点的ID
    return 0;
}
