//Solution: �ҵ��������Ĵ�������������������ȡ������Ϊÿ����Ĳ;�����
//�����г��ֵ����������Ϊÿ�ײ;ߵ��е��������
//�������*����*������-ʣ�²;߼�Ϊ����

#include <iostream>
using namespace std;

int hashtable[101];
int main() {
    int n,k;
    int *types;

    cin>>n>>k;
    types=new int[n+1];
    int max=0;
    for (int i=1;i<=n;i++) {
        cin>>types[i];
        hashtable[types[i]]++;
        if (hashtable[types[i]]>max) max=hashtable[types[i]];
    }
    int count=0;
    for (int i=1;i<=100;i++) {
        if (hashtable[i]>0) count++;
    }

    cout<<((max%k==0)?(max/k):(max/k+1))*count*k-n<<endl; //�������ȡ�������˺þ�
}
