#include<bits/stdc++.h>
using namespace std;

bool d[300];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length() ; ++i) {
        d[s[i]] = true;
    }  
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string st;
        cin >> st;
        int a = 0;
        int b = 0;
        for (int i = 0; i < st.length(); ++i) {
            if (d[st[i]]) ++b;
            if (s[i] == st[i]) ++a; 
        }
        cout << a << " " << b-a << endl;
    }
}