#include<bits/stdc++.h>
using namespace std;

int a[300000];
bool del[300000];


int main() {
    int n;
    int cntNeg = 0;
    int maxNeg = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            if (maxNeg == -1 || a[i] > a[maxNeg]) 
                maxNeg = i;
            ++cntNeg;
        }
        else if (a[i] == 0) {
            del[i] = true;
        }
    }
    if (cntNeg % 2 == 1) del[maxNeg] = true;
    int lastDel = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (del[i]) {
            ++cnt;
            if (lastDel != -1) {
                printf("1 %d %d\n", lastDel+1, i+1);
            }
            lastDel = i;
        }
    }
    if (cnt < n) {
        if (lastDel != -1) printf("2 %d\n", lastDel+1);
        int lastJoin = -1;
        for (int i = 0; i < n; ++i) {
            if (!del[i]) {
                if (lastJoin != -1) {
                    printf("1 %d %d\n", lastJoin+1, i+1);
                }
                lastJoin = i;
            }
        }
    }
}