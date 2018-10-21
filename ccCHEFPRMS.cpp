#include<bits/stdc++.h>
using namespace std;

void test() {
    
}

bool p[300];
bool semiPrime[300];
bool res[300];

void prime() {
    for (int i = 1; i <= 100; ++i) {
        p[i] = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                p[i] = false;
                break;
            }
        }
    }
    for (int i = 2; i <= 200; ++i) {
        for (int j = 2; j < sqrt(i); ++j) {
            if (i % j == 0) {
                if (p[j] && p[i/j]) {
                    semiPrime[i] = true;
                    break;
                }
            }
        }
    }
    for (int i = 2; i <= 200; ++i) {
        for (int j = 1; j < i; ++j) {
            if (semiPrime[j] && semiPrime[i-j]) {
                // if (i == 62) cerr << j << endl;
                res[i] = true;
                break;
            }
        }
    }
}


int main() {
    int t;
    prime();
    // cerr << p[3] << p[5] << semiPrime[15];
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%s\n", res[n] ? "YES" : "NO");
    }

    
}