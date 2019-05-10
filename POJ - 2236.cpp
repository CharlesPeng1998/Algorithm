#include <iostream>
#define DEBUG 0
#include <cstdio>
#include <string.h>
#define MAXN 1005
#include <math.h>
#include <string>
#define x first
#define y second
using namespace std;

int N, d;
pair<int, int> cord[MAXN];
int par[MAXN];

int find(int x){
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

bool same(int x, int y) {
  return find(x) == find(y);
}

 void unite(int x, int y) {
   int root_x = find(x);
   int root_y = find(y);
   if (root_x == root_y) return ;
   else par[root_x] = root_y;
 }

 float dis(pair<int, int>a, pair<int, int>b) {
   return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y));
 }

int main(){
  scanf("%d%d", &N, &d);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &cord[i].x, &cord[i].y);
    par[i] = -1;
  }
  char op[3];
  int p, q;
  while (scanf("%s", op) != EOF) {
    if (strcmp(op, "O") == 0) {
      scanf("%d", &p);
      if (par[p] == -1) par[p] = p;
      for (int i = 1; i <= N; i++) {
        if ((dis(cord[i], cord[p]) <= d) && (par[i] != -1)) {
          unite(i, p);
        }
      }
    }
    else if (strcmp(op, "S") == 0) {
      scanf("%d%d", &p, &q);
      if (par[p] != -1 && par[q] != -1 && same(p, q)) printf("SUCCESS\n");
      else printf("FAIL\n");
    }
  }
  return 0;
}
