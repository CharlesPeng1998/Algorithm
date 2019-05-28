// wront answer: 0.030303...
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#define DEBUG 0
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> P;
string s;
P res;

int gcd(int a, int b) {
  int r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int get_val(string s) {
  int len = int(s.length());
  int base = 1;
  int res = 0;
  for (int i = len - 1; i >= 0; i--) {
    res += (s[i] - '0') * base;
    base *= 10;
  }
  return res;
}

int my_pow(int a, int b) {
  int res = 1;
  for (int i = 0; i < b; i++) {
    res *= a;
  }
  return res;
}

int main() {
  while (cin >> s) {
    if (s == "0") break;
    res = make_pair(INF, INF);
    int num_len = s.length() - 5;
    int num = get_val(s.substr(2, num_len));
    int base = 10;
    for (int i = 1; i <= num_len; i++) {
      int a = num % base;
      int b = num / base;
      int n = i;
      int m = num_len - n;
      int up = (b * my_pow(10, n) + a) - b;
      int down = my_pow(10, m) * (my_pow(10, n) - 1);
      int g = gcd(up, down);
      up /= g;
      down /= g;
      #if DEBUG
      cout << "a: " << a << endl;
      cout << "b: " << b << endl;
      cout << "n: " << n << endl;
      cout << "m: " << m << endl;
      cout << "up: " << up << endl;
      cout << "down: " << down << endl;
      #endif
      if (down < res.second) {
        res.first = up;
        res.second = down;
      }
      base *= 10;
    }
    cout << res.first << '/' << res.second << endl;
  }
  return 0;
}
