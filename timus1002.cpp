#include<bits/stdc++.h>
using namespace std;

char toi(char ch) {
    if (ch >= 'i' && ch <= 'j') return '1';
    if (ch >= 'a' && ch <= 'c') return '2';
    if (ch >= 'd' && ch <= 'f') return '3';
    if (ch >= 'g' && ch <= 'h') return '4';
    if (ch >= 'k' && ch <= 'l') return '5';
    if (ch >= 'm' && ch <= 'n') return '6';
    if (ch == 'p' || (ch >= 'r' && ch <= 's')) return '7';
    if (ch >= 't' && ch <= 'u') return '8';
    if (ch >= 'w' && ch <= 'y') return '9';
    return '0'; 
}

bool g[200][100000];
int L[100000];
int f[200], t[200];
string s[100000];

void trace(int i) {
    if (i == 0) return;
    trace(i - L[t[i]]);
    cout << s[t[i]] << " ";
}

bool test() {
    string num;
    cin >> num;
    if (num == "-1") return false;
    int l = num.size();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        L[i] = s[i].size();
        for (int j = 0; j < l; ++j) {
            bool ok = true;
            for (int k = 0; k < s[i].size(); ++k) {
                if (num[j+k] != toi(s[i][k])) {
                    ok = false;
                    break;
                }
            }
            g[j][i] = ok;
        }
    }
    for (int i = 0; i <= l; ++i) f[i] = -1; 
    f[0] = 0;
    for (int i = 0; i < l; ++i) {
        if (f[i] != -1) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j]) {
                    if (f[i+L[j]] == -1 || f[i+L[j]] > f[i] + 1) {
                        f[i+L[j]] = f[i] + 1;
                        t[i+L[j]] = j;
                    }
                }
            }
        }
    }
    // for (int i = 0; i <= l; ++i) cout << t[i] << endl;
    if (f[l] == -1) {
        cout << "No solution.\n";
    }
    else {
        trace(l);
        cout << endl;
    }
    
    return true;
}

int main() {
    while (test());
}