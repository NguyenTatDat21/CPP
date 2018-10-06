#include<bits/stdc++.h>
using namespace std;

int n;

int a[2000];

bool test() {
    string s = "";
    cin >> s; 
    // cout << s;
    if (cin.eof()) return false;
    int l = s.size();
    a[0] = s[0] == '1';
    int p = 0;
    a[l] = 0;
    for (int i = l-1; i >= 0; --i) a[i] = a[i+1] + (s[i] == '1');
    // for (int i = 0; i < l; ++i) cout << a[i]; cout << endl;
    for (int i = 0; i < l; ++i) p += (s[i] == '1') * (i+1);
    // cout << p << endl;
    if (l == n) {
        if (p % (n+1) != 0)
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if ((p - i-1) % (n+1) == 0) {   
                    s[i] = '0';
                    break;
                } 
            }
        }
    }
    else if (l < n) {
        if (p % (n+1) == 0) {
            s += "0";
        }
        else if ((p + n) % (n+1) == 0) {
            s += "1";
        }
        else {
            for (int i = 0; i < l; ++i) {
                if ((p + a[i]) % (n+1) == 0) {
                    s.insert(i,"0");
                    break;
                }
                else if ((p+a[i]+(i+1)) % (n+1)  == 0) {
                    s.insert(i,"1");
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < l; ++i) {
            // cout << a[i+1]  << endl;
            // cout << (s[i] == '1') << endl;
            if ((p - a[i+1] - (i+1) * (s[i] == '1')) % (n+1) == 0) {
                s.erase(i,1);
                break;
            }
        }
    }
    cout << s << endl;
    return true;
    
}

int main() {
    cin >> n;
    while (test());
}