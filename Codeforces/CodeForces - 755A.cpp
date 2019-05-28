#include <iostream>
#include <string.h>
using namespace std;

const int maxn=1000010;
bool notprime[maxn];

void init() {
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for (int i=2;i<maxn;i++) {
        if (!notprime[i]) {
            if (i>maxn/i) continue; //��ֹi*i���������i,jʹ��long long��
            for (int j=i*i;j<maxn;j+=i) { //ע��������j+=i
                notprime[j]=true;
            }
        }
    }
}

int main() {
    init();
    int n;
    cin>>n;
    for (int i=1;i<=1000;i++) {
        if (notprime[n*i+1]) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
