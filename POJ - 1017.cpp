#include<iostream>
#include<cstdio>
using namespace std;

int cnt1,cnt2,cnt3,cnt4,cnt5,cnt6;
int res;
int main(){
  while (scanf("%d%d%d%d%d%d",&cnt1,&cnt2,&cnt3,&cnt4,&cnt5,&cnt6)) {
    if (!cnt1&&!cnt2&&!cnt3&&!cnt4&&!cnt5&&!cnt6) break;
    int res=0;
    res+=cnt6;
    res+=cnt5;
    if(cnt1>=cnt5*11) cnt1-=cnt5*11;
    else cnt1=0;

    res+=cnt4;
    int rest_2=cnt4*5;
    if(cnt2>=rest_2) cnt2-=rest_2;
    else {
      rest_2-=cnt2;
      cnt2=0;
      if(cnt1>=rest_2*4) cnt1-=rest_2*4;
      else cnt1=0;
    }

    int rest_3=cnt3%4;
    if(rest_3) {
      res+=cnt3/4+1;
      int space_for_2=5-(rest_3-1)*2;
      if(cnt2>=space_for_2) {
        cnt2-=space_for_2;
        if(cnt1>=(4-rest_3)*9-space_for_2*4) cnt1-=(4-rest_3)*9-space_for_2*4;
        else cnt1=0;
      }
      else {
        if(cnt1>=(4-rest_3)*9-cnt2*4) cnt1-=(4-rest_3)*9-cnt2*4;
        else cnt1=0;
        cnt2=0;
      }
    }
    else res+=cnt3/4;

    int rest=cnt2%9;
    if(rest){
      res+=cnt2/9+1;
      if(cnt1>=36-rest*4) cnt1-=36-rest*4;
      else cnt1=0;
    }
    else res+=cnt2/9;

    if(cnt1%36) res+=cnt1/36+1;
    else res+=cnt1/36;
    printf("%d\n",res);
  }
  return 0;
}
