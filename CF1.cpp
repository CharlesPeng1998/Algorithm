#include <bits/stdc++.h>
using namespace std;

int h1,m1,h2,m2;
int main(){
  scanf("%d:%d",&h1,&m1);
  scanf("%d:%d",&h2,&m2);
  int total_h,total_m;
  total_m=(m1+m2)%60;
  total_h=h1+h2+(m1+m2)/60;
  int mid_h,mid_m;
  mid_h=total_h/2;
  mid_m=(total_m+total_h%2*60)/2;

  printf("%02d:%02d\n",mid_h,mid_m);
  return 0;
}
