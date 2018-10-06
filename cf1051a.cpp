#include<bits/stdc++.h>
using namespace std;

void test() {
    string s;
    cin >> s;
    int l = s.size();
    int ok = 0, OK = 0, ok1 = 0, p = 0, P = 0, p1 = 0;
    for (int i = 0; i < l; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ++ok;
            p = i;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ++OK;
            P = i;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            ++ok1;
            p1 = i;
        } 
    }
    if (ok) {
        if (OK) {
            if (!ok1) {
                if (ok > 1) {
                    s[p] = '0';
                }
                else s[P] = '0';
            }
        }
        else {
            if (ok1) {
                if (ok > 1) {
                    s[p] = 'A';
                }
                else s[p1] = 'A';
            }
            else {
                s[0] = 'A';
                s[1] = '0'; 
            }
        }
    }
    else {
        if (OK) {
            if (ok1) {
                if (OK > 1) {
                    s[P] = 'a';
                }
                else s[p1] = 'a';
            }
            else {
                s[0] = 'a';
                s[1] = '0';
            }
        }
        else {
            s[0] = 'A';
            s[1] = 'a';
        }
    }
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        test();
    }
}