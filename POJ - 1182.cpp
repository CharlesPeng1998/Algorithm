#include <iostream>
#include <string.h>
#include <cstdio>
#define MAXN 50005
using namespace std;

int N, K;
int D, X, Y;
int par[3 * MAXN];
#if DEBUG
int used[3 * MAXN];
#endif

int find(int x){
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

bool same(int x, int y) {
  int root_X = find(x);
  int root_Y = find(y);
  if (root_X == root_Y) return true;
  else return false;
}

void unite(int x, int y) {
  int root_X = find(x);
  int root_Y = find(y);
  if (root_X == root_Y) return;
  par[root_X] = root_Y;
  return ;
}

int main() {
  cin >> N >> K;
  int wa = 0;
  for (int i = 1; i <= 3 * N; i++) par[i] = i;
  for (int i = 1; i <= K; i++) {
    scanf("%d%d%d", &D, &X, &Y);
    if (X > N || Y > N) {wa++; continue;}
    if (D == 1) {
      if (same(X, Y + N) || same(X, Y + 2 * N)) wa++;
      else {
        unite(X, Y);
        unite(X + N, Y + N);
        unite(X + 2 * N, Y + 2 * N);
      }
    }
    else if (D == 2){
      if (same(X, Y) || same(X, Y + 2 * N)) wa++;
      else {
        unite(X, Y + N);
        unite(X + N, Y + 2 * N);
        unite(X + 2 * N, Y);
      }
    }
  }

  cout << wa << endl;
  return 0;
}
