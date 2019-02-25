/*解题思路：
逆向思维，考虑最终状态01234567到给定状态的步数
每一个状态可以通过0的一次移动到达下一个状态，因此可使用BFS
从最终状态开始搜索全部状态
利用map记录某个状态到最终状态的步数
执行一次bfs函数，便可从map中查找到所有结果
*/

#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;
map<string,int> my_map;
queue<string> my_queue;

void bfs() {
  string init="01234567";
  my_map[init]=0;
  my_queue.push(init);
  while (!my_queue.empty()) {
    string curr_stat=my_queue.front(); my_queue.pop();
    int pos;
    for (pos=0;pos<int(curr_stat.length());pos++) {
      if (curr_stat[pos]=='0') break;
    }
    if ((pos>=0&&pos<3)||(pos>=4&&pos<7)) {
      string next_stat=curr_stat;
      char temp=next_stat[pos];
      next_stat[pos]=next_stat[pos+1];
      next_stat[pos+1]=temp;
      if (my_map.count(next_stat)==0) {
        my_map[next_stat]=my_map[curr_stat]+1;
        my_queue.push(next_stat);
      }
    }
    if (pos>=0&&pos<=3) {
      string next_stat=curr_stat;
      char temp=next_stat[pos];
      next_stat[pos]=next_stat[pos+4];
      next_stat[pos+4]=temp;
      if (my_map.count(next_stat)==0) {
        my_map[next_stat]=my_map[curr_stat]+1;
        my_queue.push(next_stat);
      }
    }
    if ((pos>0&&pos<=3)||(pos>4&&pos<=7)) {
      string next_stat=curr_stat;
      char temp=next_stat[pos];
      next_stat[pos]=next_stat[pos-1];
      next_stat[pos-1]=temp;
      if (my_map.count(next_stat)==0) {
        my_map[next_stat]=my_map[curr_stat]+1;
        my_queue.push(next_stat);
      }
    }
    if (pos>=4&&pos<=7) {
      string next_stat=curr_stat;
      char temp=next_stat[pos];
      next_stat[pos]=next_stat[pos-4];
      next_stat[pos-4]=temp;
      if (my_map.count(next_stat)==0) {
        my_map[next_stat]=my_map[curr_stat]+1;
        my_queue.push(next_stat);
      }
    }
  }
}

int main() {
  string input;
  bfs();
  while (getline(cin,input)) {
    string str;
    for (int i=0;i<int(input.length());i++) {
      if (input[i]!=' ') str+=input[i];
    }
    cout<<my_map[str]<<endl;
  }
  return 0;
}
