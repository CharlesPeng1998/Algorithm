/*总之从这道题学到的教训是：
1.最短路径用BFS
2.如何记录BFS的层数
3.能用int就不要用string， 多慢啊
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <queue>
#define DEBUG 1
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> P;
const int maxn = 10005;
int s, t;
int n;
int min_step;
bool notprime[maxn];
bool vis[maxn];
int base[] = {1, 10, 100};

void init() {
  memset(notprime, false, sizeof notprime);
  notprime[0] = notprime[1] = true;
  for (int i =2; i < maxn; i++) {
    if (!notprime[i]) {
      if (i > maxn / i) continue;
      for (int j = i * i; j < maxn; j += i) notprime[j] = true;
    }
  }
}

bool bfs(int s, int t) {
  memset(vis, false, sizeof vis);
  queue<P> que;
  vis[s] = true;
  que.push(make_pair(s, 0));
  while (!que.empty()) {
    P head = que.front();
    que.pop();
    if (head.first == t) {
      min_step = head.second;
      return true;
    }
    for (int i = 1; i <= 9; i++) {
      int tmp = head.first % 1000 + i * 1000;
      if (!notprime[tmp] && !vis[tmp]) {
        que.push(make_pair(tmp, head.second + 1));
        vis[tmp] = true;
      }
    }
    for (int i = 0; i <= 2; i++) {
      for (int j = 0; j <= 9; j++) {
        int digit = head.first%(base[i]*10)/base[i];
        int tmp = head.first - digit * base[i] + j * base[i];
        if (!notprime[tmp] && !vis[tmp]) {
          que.push(make_pair(tmp, head.second + 1));
          vis[tmp] = true;
        }
      }
    }
  }
  return false;
}

int main() {
  init();
  cin >> n;
  while (n--) {
    cin >> s >> t;
    if (bfs(s, t)) cout << min_step << endl;
    else cout << "Impossible" << endl;
  }
  return 0;
}
