#include<bits/stdc++.h>
using namespace std;

int setbit(int x, int i) {
    return x | (1 << i);
}

int n;
int c[2000], t[2000];
int f[8];


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> c[i];
        cin >> s;
        for (auto ch : s) {
            t[i] = setbit(t[i],ch-'A');
        }
    } 
    for (int j = 0; j < 8; ++j) {
        f[j] = -1;
    }
    f[0] = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < 8; ++j) {
            if (f[j] != -1) {
                if (f[j | t[i]] == -1) f[j | t[i]] = f[j] + c[i];
                else f[j | t[i]] = min(f[j | t[i]], f[j] + c[i]);
            } 
        }
    cout << f[7];
}