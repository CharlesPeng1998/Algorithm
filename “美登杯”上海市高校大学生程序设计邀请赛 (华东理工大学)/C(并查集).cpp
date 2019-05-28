#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int n, k;
map<vector<int>, int> mp;
vector<int> color[maxn];
int par[11][maxn];

int find(int x, int id) {
	if (par[id][x] == x) return x;
	else return par[id][x] = find(par[id][x], id);
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cin >> n >> k;
  	for (int i = 0; i < 11; i ++) {
    	for (int j = 1; j <= n; j ++) {
      		par[i][j] = j;
    	}
  	}
  	for (int i = 0; i < k; i ++) {
    	int m;
    	cin >> m;
		for (int j = 0; j < m; j ++) {
			int u, v;
			cin >> u >> v;
			int x = find(u, i);
		 	int y = find(v, i);
			if (x != y) par[i][x] = y;
		}
  	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < k; j ++) {
			color[i].push_back(find(i, j));
		}
		if (!mp.count(color[i])) mp[color[i]] = 1;
		else mp[color[i]] ++;
	}
	for (int i = 1; i <= n; i ++) {
		cout << mp[color[i]] << endl;
	}
  	return 0;
}
