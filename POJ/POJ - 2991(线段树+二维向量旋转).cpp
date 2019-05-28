#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

const int maxn = 1e4 + 5;
const int SIZE = 1 << 15;
int n, c;
int L[maxn];
int S[maxn], A[maxn];
double x[SIZE], y[SIZE], ang[SIZE]; // 将左右儿子区间进行连接，右儿子需要旋转的角度
double currAng[maxn]; // 每个线段之间的当前角度

void init(int k, int l, int r) {
	ang[k] = x[k] = 0.0;
	if (r - l == 1) {
		y[k] = L[l];
	}
	else {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		init(chl, l, (l + r) / 2);
		init(chr, (l + r) / 2, r);
		y[k] = y[chl] + y[chr];
	}
}

void change(int s, double a, int k, int l, int r) { // 角度更新从叶子结点开始
	if (s > l && s < r) {
		int chl = 2 * k + 1;
		int chr = 2 * k + 2;
		int m = (l + r) / 2;
		change(s, a, chl, l, m);
		change(s, a, chr, m, r);
		if (s <= m) ang[k] += a;

		double vlSin = sin(ang[k]);
		double vlCos = cos(ang[k]);
		x[k] = x[chl] + (vlCos * x[chr] - vlSin * y[chr]);
		y[k] = y[chl] + (vlCos * y[chr] + vlSin * x[chr]);
	}
}

int main() {
	while(~scanf("%d%d", &n, &c)) {
		for (int i = 0; i < n; i ++) scanf("%d", L + i);
		for (int i = 0; i < c; i ++) scanf("%d%d", S + i, A + i);
		init(0, 0, n);
		for (int i = 0; i < n; i ++) currAng[i] = PI;
		for (int i = 0; i < c; i ++) {
			double a = A[i] / 180.0 * PI;
			int s = S[i];
			change(s, a - currAng[s], 0, 0, n);
			currAng[s] = a;
			printf("%.2f %.2f\n", x[0], y[0]);
		}
		printf("\n");
	}
	return 0;
}
