#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int f[2000][2000];
int m[2000];

int main() {
    cin >> s;
    cin >> n;
    int l = s.size();
    m[l-1] = 1 % n;
    for (int i = l - 2; i >= 0; --i) {
        m[i] = (m[i+1] * 10) % n;

    }
    for (int i = 0; i <= l; ++i) 
        for (int j = 0; j <= n; ++j)
            f[i][j] = -1;
    f[l][0] = 0;
    for (int i = l-1; i >= 0; --i) {
        if (s[i] == '?') {
            for (int j = 0; j < n; ++j) {
                for (int k = (i == 0 ? 1 : 0); k < 10; ++k) {
                    if (f[i][j] == -1) {
                        int jj = ((j - k * m[i]) % n + n) % n;
                        if (f[i+1][jj] != -1) f[i][j] = k;
                    } 
                }
            }
        } 
        else {
            for (int j = 0; j < n; ++j) {
                int k = s[i] - '0';
                int jj = ((j - k * m[i]) % n + n) % n;
                if (f[i+1][jj] != -1) f[i][j] = k;
            }
        }
    }
    if (f[0][0] == -1) cout << '*';
    else {
        int j = 0;
        for (int i = 0; i < l; ++i) {
            cout << f[i][j];
            j = ((j - f[i][j] * m[i]) % n + n) % n;
        }
    }
}