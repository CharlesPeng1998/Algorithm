// �ʼ���뷨�ǿ�������λ�ú�ż��λ���Ϸֱ��������a��b��Ϊȷ��ֵ
// �����������a == b�Ļ�����������
// ���Էֱ��������к�ż���������͵ڶ����a b c d
// ���a == c ��ô����ض���a d��b c�������֮��

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int v[maxn];
int cnt[maxn];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> v[i];
	int a = 0, b = 0, f1 = 0, s1 = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i += 2) {
		cnt[v[i]] ++;
		if (cnt[v[i]] > f1) {
			if (b != a) {
				b = a;
				s1 = f1;
			}
			a = v[i];
			f1 = cnt[v[i]];
		}
		else if (cnt[v[i]] > s1) {
			b = v[i];
			s1 = cnt[v[i]];
		}
	}
	if (a == b) b = a + 1;
	int c = 0, d = 0, f2 = 0, s2 = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i < n; i += 2) {
		cnt[v[i]] ++;
		if (cnt[v[i]] > f2) {
			if (c != d) {
				d = c;
				s2 = f2;
			}
			c = v[i];
			f2 = cnt[v[i]];
		}
		else if (cnt[v[i]] > s2) {
			d = v[i];
			s2 = cnt[v[i]];
		}
	}
	if (c == d) d = c + 1;
	if (a != c) {
		int res = 0;
		for (int i = 0; i < n; i ++) {
			if (i % 2 == 0 && v[i] != a) res ++;
			else if (i % 2 != 0 && v[i] != c) res ++;
		}
		cout << res << endl;
	}
	else {
		int res1 = 0, res2 = 0;
		for (int i = 0; i < n; i ++) {
			if (i % 2 == 0 && v[i] != a) res1 ++;
			else if (i % 2 != 0 && v[i] != d) res1 ++;
		}
		for (int i = 0; i < n; i ++) {
			if (i % 2 == 0 && v[i] != b) res2 ++;
			else if (i % 2 != 0 && v[i] != c) res2 ++;
		}
		cout << min(res1, res2) << endl;
	}
	return 0;
}
