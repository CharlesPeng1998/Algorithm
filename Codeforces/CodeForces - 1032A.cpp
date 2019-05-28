//Solution: 找到出现最多的次数除客人数量（向上取整）即为每人配的餐具套数
//序列中出现的种类个数即为每套餐具当中的种类个数
//种类个数*套数*客人数-剩下餐具即为所求

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

    cout<<((max%k==0)?(max/k):(max/k+1))*count*k-n<<endl; //这个向上取整折腾了好久
}
