#include <stdio.h>
#include <algorithm>
#include <string.h>
#define l first
#define w second
#include <iostream>
using namespace std;

int T,n;
pair<int, int> stick[5005];
int dp[5005];
bool compare(pair<int, int> a, pair<int, int> b){
    return a.l<b.l || (a.l==b.l && a.w<b.w);
}

int main()
{
    cin>>T;
    while(T--){
        int res=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>stick[i].l>>stick[i].w;
        }
        sort(stick,stick+n,compare);
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(stick[j].w>stick[i].w&&(dp[j]+1)>dp[i]) dp[i]=dp[j]+1;
            }
            if(dp[i]>res) res=dp[i];
        }
        cout<<res<<endl;
    }

    return 0;
}
