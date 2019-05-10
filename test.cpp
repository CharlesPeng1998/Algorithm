#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxn 100100
#define LL long long

int n;
LL a[maxn],k;

bool deal(LL mid)
{
    LL sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid){
            sum+=(a[i]-mid)/k;
            if((a[i]-mid)%k)
                sum++;
            if(sum>mid)
                return false;
        }
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        LL big=0,ans;
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            big=big>a[i]?big:a[i];
        }
        scanf("%lld",&k);
        if(k==1){
            printf("%lld\n",big);
            continue;
        }


        LL left=1,right=big;
        LL mid;
        k--;
        while(left<=right)
        {
            mid=(right-left)*0.5+left;
            if(deal(mid))
                right=mid-1,ans=mid;
            else
                left=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
