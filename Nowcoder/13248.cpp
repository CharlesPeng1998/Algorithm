#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int N;
char a[maxn], b[100005];
int maxVl;

struct Node {
	int A;
	int C;
	int G;
	int T;
	int l, r;

	Node(int nA, int nC, int nG, int nT, int L, int R) {
		A = nA;
		C = nC;
		G = nG;
		T = nT;
		l = L;
		r = R;
	}
	Node() {}
} tree[4 * maxn];

void Init(int k, int l, int r) {
	if (l == r) {
		switch(a[l]) {
			case 'A': tree[k].A ++; break;
			case 'C': tree[k].C ++; break;
			case 'G': tree[k].G ++; break;
			case 'T': tree[k].T ++; break;
		}
		tree[k].l = tree[k].r = l;
	}
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		int m = (l + r) / 2;
		Init(chl, l, m);
		Init(chr, m + 1, r);
		tree[k].A = tree[chl].A + tree[chr].A;
		tree[k].C = tree[chl].C + tree[chr].C;
		tree[k].G = tree[chl].G + tree[chr].G;
		tree[k].T = tree[chl].T + tree[chr].T;
		tree[k].l = l;
		tree[k].r = r;
	}
}

Node Query(int p, int q, int k, int l, int r) {
	if (r < p || q < l) {
		return Node(0, 0, 0, 0, 0, 0);
	}
	else if (p <= l && r <= q) {
		return tree[k];
	}
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		int m = (l + r) / 2;
		Node node1 = Query(p, q, chl, l, m);
		Node node2 = Query(p, q, chr, m + 1, r);
		int nA = node1.A + node2.A;
		int nC = node1.C + node2.C;
		int nG = node1.G + node2.G;
		int nT = node1.T + node2.T;
		return Node(nA, nC, nG, nT, 0, 0);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i ++) {
		scanf("%s%s", a, b);
		strcat(a, b);
		int len = strlen(a);
		memset(tree, 0, sizeof tree);
		Init(0, 0, len - 1);
		maxVl = 0;
		for (int i = 0; i < len - 1; i ++) {
			Node node1 = Query(0, i, 0, 0, len - 1);
			Node node2 = Query(i + 1, len - 1, 0, 0, len - 1);
			int vl = min(node1.A, node2.A)+min(node1.C, node2.C)+min(node1.G, node2.G)+min(node1.T, node2.T);
			maxVl = max(maxVl, vl);
		}
		printf("%d\n", maxVl);
	}
	return 0;
}
