#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
int n;
vector<int> a;
int b[maxn];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
		a.push_back(b[i]);
	}
	int cnt = 1;
	while (1) {
		int m = n % 2 == 0 ? n / 2 : n / 2 + 1;
		for (int i = 0; i < n; i ++) {
			if (i + m < n) {
				swap(a[i], a[i + m]);
			}
			else break;
		}
		int flag = 1;
		for (int i = 0; i < n; i ++) {
			if (a[i] != b[i]) {
				flag = 0;
				break;
			}
		}
		if (flag) break;
		else cnt ++;

		for (int i = 1; i < n; i += 2) {
			swap(a[i], a[i - 1]);
		}
		flag = 1;
		for (int i = 0; i < n; i ++) {
			if (a[i] != b[i]) {
				flag = 0;
				break;
			}
		}
		if (flag) break;
		else cnt ++;
	}
	cout << cnt << endl;
	return 0;
}
