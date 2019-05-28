#include <iostream>
#include <string>
using namespace std;

int cnt1,cnt2,cnt3,cnt4;

int main() {
  cin>>cnt1>>cnt2>>cnt3>>cnt4;
  if (cnt3>0) {
    if (cnt1>0&&cnt4>0&&cnt1==cnt4) cout<<1<<endl;
    else cout<<0<<endl;
  }
  else {
    if (cnt1==cnt4) cout<<1<<endl;
    else cout<<0<<endl;
  }
  return 0;
}
