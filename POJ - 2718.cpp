/*解题思路：
利用algorithm中的next_permutation枚举数字的全排列。
注意到若要使得两个数的差最小，则两个数的位数相等（偶数位）或者差1（奇数位），
因此从len/2位置开始划分，并且要确保首位数字不为0（35行和37行）
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;

int T;
int res;
char input[50];
char str[20];

int main() {
  cin>>T;
  getchar();
  while (T--) {
    res=INF;
    char c;
    int i=0;
    while ((c=getchar())!='\n') {
      if (c>='0' && c<='9') str[i++]=c;
    }
    str[i]='\0';

    if (i==2) {
      cout<<int(str[1]-str[0])<<endl;
    }
    else {
      while(str[0]=='0') next_permutation(str,str+i);
      do {
        if (str[i/2]!='0') {
          int a=int(str[0]-'0');
          for (int j=1;j<i/2;j++) {
            a=a*10+int(str[j]-'0');
          }
          int b=int(str[i/2]-'0');
          for (int j=i/2+1;j<i;j++) {
            b=b*10+int(str[j]-'0');
          }
          int ans=abs(a-b);
          if(ans<res) res=ans;
        }
/* 如果do循环块中为以下代码则TLE  个人怀疑是不是atoi函数影响了效率？
if (str[i/2]!='0') {
          char str2[20]; strcpy(str2,str);
          str2[i/2]='\0';
          int ans=abs(atoi(str2)-atoi(str+i/2));
          if (ans<res) res=ans;
        }
*/
      }while (next_permutation(str,str+i));
      cout<<res<<endl;
    }
  }
  return 0;
}
