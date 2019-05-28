#include <bits/stdc++.h>

using namespace std;

const int maxn = 50005;
int T, N;
char inst[10];
int data[3 * maxn];
int a[maxn];
int ans[maxn];

void Init(int k, int l, int r) {
	if (r - l == 1) data[k] = a[l];
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		Init(chl, l, (l + r) / 2);
		Init(chr, (l + r) / 2, r);
		data[k] = data[chl] + data[chr];
	}
}

void Add(int i, int j, int k, int l, int r) {
	 if (l <= i && i < r) {
		 if (r - l == 1) {
			 data[k] += j;
		 }
		 else {
			 int chl = 2 * k + 1;
			 int chr = 2 * k + 2;
			 int m = (l + r) / 2;
			 Add(i, j, chl, l, m);
			 Add(i, j, chr, m, r);
			 data[k] = data[chl] + data[chr];
		 }
	 }
}

void Sub(int i, int j, int k, int l, int r) {
	if (l <= i && i < r) {
		if (r - l == 1) {
			data[k] -= j;
		}
		else {
			int chl = 2 * k + 1;
			int chr = 2 * k + 2;
			int m = (l + r) / 2;
			Sub(i, j, chl, l, m);
			Sub(i, j, chr, m, r);
			data[k] = data[chl] + data[chr];
		}
	}
}

int Query(int i, int j, int k, int l, int r) {
	if (j < l || i >= r) return 0; // 无交集
	else if (i <= l && l <= j && i < r && r <= j + 1) return data[k]; // 完全包含
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		int m = (l + r) / 2;
		return Query(i, j, chl, l, m) + Query(i, j, chr, m, r);
	}
}

int main() {
	scanf("%d", &T);
	int cnt = 1;
	while (T -- ) {
		int idx = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i ++) scanf("%d", a + i);
		memset(data, 0, sizeof data);
		Init(0, 0, N);
		while (scanf("%s", inst)) {
			if (!strcmp(inst, "End")) break;
			else if (!strcmp(inst, "Add")) {
				int i, j; cin >> i >> j;
				Add(i - 1, j, 0, 0, N);
			}
			else if (!strcmp(inst, "Sub")) {
				int i, j; cin >> i >> j;
				Sub(i - 1, j, 0, 0, N);
			}
			else if (!strcmp(inst, "Query")) {
				int i, j; cin >> i >> j;
				ans[idx ++] = Query(i - 1, j - 1, 0, 0, N);
			}
		}
		printf("Case %d:\n", cnt ++);
		for (int i = 0; i < idx; i ++) printf("%d\n", ans[i]);
	}
	return 0;
}
