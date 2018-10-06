#include<bits/stdc++.h>
using namespace std;

int a[200], cnt[200], t[200];
vector<int> s;

int main() {
    int n;
    int p = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    for (int i = 1; i <= 100; ++i) {
        if (cnt[i] == 1) {
            s.push_back(i);
        }
        if (cnt[i] > 2) {
            p = i;
        }
    }
    for (int i = 0; i < s.size()/2; ++i) {
        t[s[i]] = 1;
    }
    if (s.size() % 2 == 1 && p == 0) {
        printf("NO");
    }
    else {
        if (s.size() % 2 == 1) {
            t[p] = 2;
        }
        printf("YES\n");
        for (int i = 1; i <= n; ++i) {
            printf("%c", t[a[i]] ? 'A' : 'B');
            if  (t[a[i]] == 2) t[a[i]] = 0;
        }
    }
}