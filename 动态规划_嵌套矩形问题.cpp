#include<iostream>
#include<memory.h>
using namespace std;

int gra[100][100];
int len[100];//�Ӹõ㿪ʼ���·������
int n;

struct mat
{
    int a,b;
};

//��̬�滮��DAG�ϵ��·��
//��len�����¼���ڵ�������·������ʼ��Ϊ0
//������״̬Ϊlen[i]
//״̬ת�Ʒ��̣�len[i]=max(len[i],len[j]+1)
//�ú��������˱����ظ�����ĵݹ飺���仯����
int f(int pos)
{
    //len[pos]������˵���Ѽ������ֱ�ӷ��ؽ���������ظ�����
    if(len[pos] > 0)
    {
        return len[pos];
    }
    //δ������Ľ�㣬���·����ʼΪ1
    len[pos] = 1;

    //��ʼ����״̬ת�Ʒ������·��
    for(int i = 0; i < n; i ++)
    {
        if(gra[pos][i])
        {
            len[pos] = max(len[pos], f(i) + 1);
        }
    }
    return len[pos];
}

//ʹ�ñ���ֵ�����С�ı�Ŵ�ӡ
//ͬ��ʹ���˵ݹ�
void print(int i)
{
    cout << i << ' ';

    //�ӵ͵��߱������Ѱ�������Ԫ��ϵ��״̬ת�Ƶ���һ�����
    //�ٶ��ҵ�����һ���������ͬ�Ĳ���
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
                gra[i][j] = 1;//�ö�ά���������о��п�Ƕ�׶�Ԫ��ϵ��[i,j]
            }
        }
    }
    int matid = 0;
    for(int i = 0; i < n; i ++)
    {
        //��ÿһ����㿪ʼ���·��
        if(f(i) > ans)
        {
            ans = f(i);
            matid = i;//��¼���·�����׽��ID����ӡID��Ҫ
        }
    }
    cout << ans << endl;
    print(matid); //���ֵ�����С��ӡ·���Ͻ���ID
    return 0;
}
