#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int N;
int balls[10];

bool dfs(int n,stack<int> &s1, stack<int> &s2) {
  if (n==10) return true;
  if (s1.empty() || balls[n]>s1.top()) {
    s1.push(balls[n]);
    if (dfs(n+1,s1,s2)) return true;
    else s1.pop();
  }
  if (s2.empty() || balls[n]>s2.top()) {
    s2.push(balls[n]);
    if (dfs(n+1,s1,s2)) return true;
    else s2.pop();
  }
  return false;
}

int main() {
  cin>>N;
  while (N--) {
    stack<int> s1,s2; //最初把这两个栈作为全局变量，每次测试的结果影响了下一次测试，导致WA
                      //要注意！
    for (int i=0;i<10;i++) {
      cin>>balls[i];
    }
    if (dfs(0,s1,s2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


  }
}
