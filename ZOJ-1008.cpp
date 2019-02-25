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

int size;
int square[26][4];
int mark[26];


//used:��ǰ�Ѿ�ʹ�õķ�������.sqaure_no:��ǰ�������������ķ�����
//row,col:�������������ķ�����õ�����
bool DFS(int square_no,int row,int col)
{
    bool over;
    //������ȫ��ʹ�ã���˵����Ϸ�����
    for (int i=1;i<=size*size;i++)
    {
        if (mark[i]==0)
        {
            over=0;
        }
    }
    if (over)
    {
        return true;
    }

    //Ϊ����Ѱ���ϱ�ƥ���
    if (row!=0)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][2]==square[square_no][0] && mark[i]!=1)
            {
                mark[i]=1;
                //��ƥ��ķ���������ݹ���������
                if (DFS(i,row-1,col))
                {
                    return 1;
                }
                else mark[i]=0; //���������û�б�Ҫ��
            }
        }
    }

    //Ѱ���ұ�ƥ���
    if (col!=size-1)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][3]==square[square_no][1] && mark[i]!=1)
            {
                mark[i]=1;
                //��ƥ��ķ���������ݹ���������
                if (DFS(i,row,col+1))
                {
                    return 1;
                }
                else mark[i]=0;
            }
        }
    }

    //Ѱ���±�ƥ��
    if (row!=size-1)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][0]==square[square_no][2] && mark[i]!=1)
            {
                mark[i]=1;
                //��ƥ��ķ���������ݹ���������
                if (DFS(i,row+1,col))
                {
                    return 1;
                }
                else mark[i]=0;
            }
        }
    }

    //Ѱ�����ƥ��
    if (col!=0)
    {
        for (int i=1;i<=size*size;i++)
        {
            if (square[i][1]==square[square_no][3] && mark[i]!=1)
            {
                mark[i]=1;
                //��ƥ��ķ���������ݹ���������
                if (DFS(i,row,col-1))
                {
                    return 1;
                }
                else mark[i]=0;
            }
        }
    }

    return 0;
}

int main()
{
    int count=1;

    while (1)
    {
        scanf("%d",&size);
        if (size==0)
            break;

        for (int i=1;i<=size*size;i++)
        {
            scanf("%d %d %d %d",&square[i][0],&square[i][1],&square[i][2],&square[i][3]);
        }

        bool flag=0;

        memset(mark,0,sizeof(mark));
        mark[1]=1;
        for (int j=0;j<size;j++)
        {
            for (int k=0;k<size;k++)
            {
                if (DFS(1,j,k))
                {
                    flag=1;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        mark[1]=0;

        if (flag)
            cout<<"Game "<<(count++)<<": Possible"<<endl<<endl;
        else cout<<"Game "<<(count++)<<": Impossible"<<endl<<endl;
    }
    return 0;
}
