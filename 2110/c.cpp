#include<bits/stdc++.h>
using namespace std;



vector<long long> process(string s) {
    vector<long long> ret;
    long long tmp = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            if (i != 0) ret.push_back(tmp);
            ret.push_back(s[i]);
            tmp = 0;
        }
        else {
            tmp = tmp * 10 + s[i] - '0';
        }
    }
    ret.push_back(tmp);
    return ret;
}

vector<long long> a, b;
long long p, c;

bool test() {
    string t;
    getline(cin, t);
    if (t[0] != '@') return false;
    string st;
    long long s = 0;
    bool start = false, end = false;
    switch(t[1]) {
        case '1':
            getline(cin, st);
            a = process(st);
            getline(cin, st);
            b = process(st);
            // for (int i = 0; i < a.size(); ++i) cerr << a[i] << endl;
            
            cout << t << ": ";
            if (a.size() > 1 && a[a.size()-2] == b[0]) {
                b[1] += a[a.size()-1];
                a.pop_back();
                a.pop_back();
            }
            for (int i = 0; i < a.size(); ++i) {
                if (i % 2 == 0) cout << char(a[i]);
                else cout << a[i];
            }
            for (int i = 0; i < b.size(); ++i) {
                if (i % 2 == 0) cout << char(b[i]);
                else cout << b[i];
            }
            break;
        case '2': 
            getline(cin, st);
            a = process(st);
            cin >> p >> c;
            getline(cin, st);
            cout << t << ": ";
            s = 0;
            start = false;
            end = false;

            for (int i = 1; i < a.size(); i += 2) {
                s += a[i];
                if (!start && s >= p) {
                    start = true;
                    a[i] -= s - p + 1;
                } 
                else if (start) a[i] = 0;
                if (s > p + c - 1) {
                    a[i] += s - p - c + 1;
                    break;
                }   
            }
            for (int i = 1; i < a.size(); i += 2) {
                if (a[i]) {
                    cout << char(a[i-1]) << a[i];
                }
            }
            break;
        case '3':
            getline(cin, st);
            a = process(st);
            cin >> p >> c;
            getline(cin, st);
            cout << t << ": ";
            s = 0;
            start = false, end = false;
            for (int i = 1; i < a.size(); i += 2) {
                s += a[i];
                
                if (!start) {
                    a[i] = 0;
                    if (s >= p) {
                        a[i] += s - p + 1;
                        start = true;
                    }
                }
                else {
                    if (!end && s > p + c - 1) {
                        a[i] -= s - p - c + 1;
                        end = true;
                    }
                    else if (end) a[i] = 0;
                }
                
            }
            for (int i = 1; i < a.size(); i += 2) {
                if (a[i]) {
                    cout << char(a[i-1]) << a[i];
                }
            }
            break;
        case '4':
            getline(cin, st);
            a = process(st);
            getline(cin, st);
            b = process(st);
            cin >> p;
            getline(cin, st);
            cout << t << ": ";
            // start = true;
            s = 0;
            int k = 0;
            // cerr << p << endl;
            for (int i = 1; i < a.size(); i += 2) {
                s += a[i];
                // cerr << s << endl;
                if (s >= p) {
                    start = true;
                    k = i;
                    if (b.size() > 1 && b[b.size()-2] == a[i-1]) b[b.size()-1] += s-p+1;
                    else {
                        b.push_back(a[i-1]);
                        b.push_back(s - p + 1);
                    }
                    // for (int j = 0; j < b.size(); ++j) cerr << b[j] << endl;
                    a[i] -= s - p + 1;
                    if (i > 1 && a[i] == 0) {
                        i -= 2;
                    }
                    if (a[i-1] == b[0]) {
                        b[1] += a[i];
                        a[i] = 0;
                    }
                    // for (int j = 0; j < b.size(); ++j) cerr << b[j] << endl;
                    break;
                }
            } 
            // cerr << k << endl;
            for (int i = 1; i < a.size(); i += 2) {
                if (a[i]) {
                    cout << char(a[i-1]) << a[i];
                }
                if (i == k) {
                    for (int j = 1; j < b.size(); j += 2) {
                        cout << char(b[j-1]) << b[j];
                    }
                } 
            }

        break;
    }
    cout << endl;
    return true;
}

int main() {
    while (test());
}