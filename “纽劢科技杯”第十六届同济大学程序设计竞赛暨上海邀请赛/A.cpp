 #include <bits/stdc++.h>

 using namespace std;

int n;
 int main() {
   cin >> n;
   int d_1000 = n / 1000;
   for(int i = 0; i < d_1000; i++) cout << 'M';
   n %= 1000;
   int d_100 = n / 100;
   if (d_100 >= 5) {
     if (d_100 == 9) cout << "CM";
     else {
       cout << 'D';
       d_100 -= 5;
       for (int i = 0; i < d_100; i++) cout << 'C';
     }
   }
   else {
     if (d_100 == 4) cout << "CD";
     else {
       for (int i = 0; i < d_100; i++) cout << 'C';
     }
   }
   n %= 100;
   int d_10 = n / 10;
   if (d_10 >= 5) {
     if (d_10 == 9) cout << "XC";
     else {
       cout << 'L';
       d_10 -= 5;
       for (int i = 0; i < d_10; i++) cout << 'X';
     }
   }
   else {
     if (d_10 == 4) cout << "XL";
     else {
       for (int i = 0; i < d_10; i++) cout << 'X';
     }
   }
   n %= 10;
   if (n >= 5) {
     if (n == 9) cout << "IX";
     else {
       cout << 'V';
       n -= 5;
       for (int i = 0; i < n; i++) cout << 'I';
     }
   }
   else {
     if (n == 4) cout << "IV";
     else {
       for (int i = 0; i < n; i++) cout << 'I';
     }
   }
   cout << endl;
   return 0;
 }
